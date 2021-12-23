#ifdef _DEBUG
#    define _DEBUG_WAS_DEFINED 1
#undef _DEBUG
#endif

#include <stdio.h>
#include <Python.h>

int main() {
	PyObject* pName, * pModule, * pFunc, * pValue;
	PyObject* res;

	Py_Initialize();

	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('C:/dev/')");
	pName = PyUnicode_FromString("koko");
	pModule = PyImport_Import(pName);

	PyObject* getResult = PyObject_CallMethod(pModule, "getResult", "");

	//PyObject* objectsRepresentation = PyObject_Repr(getResult);
	//const char* s = PyString_AsString(objectsRepresentation);

	PyObject* repr = PyObject_Repr(getResult);
	const char* str = PyUnicode_AsEncodedString(repr, "utf-8", "~E~");
	const char* bytes = PyBytes_AS_STRING(str);

	//PyObject* multiply = PyObject_GetAttrString(pModule, "getResult");
	//res = PyObject_CallFunction(multiply, "");

	//pFunc = PyObject_GetAttrString(pModule, "getResult");
	//pValue = PyObject_CallObject(pFunc, NULL);

	if (bytes) {
		/* print res */
		printf("%s\n", bytes);
	}

	Py_Finalize();

	return 0;

}