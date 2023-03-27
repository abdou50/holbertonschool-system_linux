void print_python_list(PyObject *p)
{
    printf("[*] Python list info");
    printf("[*] Size of the Python List = %lu", PyList_Size(p))
}