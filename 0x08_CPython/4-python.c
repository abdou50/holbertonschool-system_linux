#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

/**
 * print_python_string - prints a Python string using macros
 * @p: pointer to PyObject
 */
void print_python_string(PyObject *p)
{
	wprintf("[.] string object info\n");
	if (!p || p->ob_type != &PyUnicode_Type)
	{
		wprintf("  [ERROR] Invalid String Object\n");
		return (-1);
	}
	if (((PyASCIIObject *)p)->state.ascii)
		wprintf("  type: compact ascii\n");
	else
		wprintf("  type: compact unicode object\n");
	wprintf("  length: %ld\n", ((PyASCIIObject *)p)->length);
	wprintf("  value: %ls\n", PyUnicode_AS_UNICODE(p));
}
