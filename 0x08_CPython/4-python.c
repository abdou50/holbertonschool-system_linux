#include <Python.h>

void print_python_string(PyObject *p)
{
    Py_ssize_t length;
    wchar_t *wstr;
    char *str;

    if (!PyUnicode_Check(p)) {
        fprintf(stderr, "Error: Invalid Python string\n");
        return;
    }

    length = PyUnicode_GetLength(p);
    wstr = PyUnicode_AsWideCharString(p, &length);
    str = Py_EncodeLocale(wstr, NULL);

    if (str == NULL) {
        fprintf(stderr, "Error: Unable to convert Python string\n");
        return;
    }

    printf("'%s'\n", str);

    PyMem_Free(wstr);
    PyMem_Free(str);
}
