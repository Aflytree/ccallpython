#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <Python.h>
#include "vectorTest.h"
using namespace std;

FILE*filestream;
FILE*stream;

int main(int argc, char *argv[])
{
    PyObject *pName, *pModule, *pDict, *pFunc;
    PyObject *pArgs, *pValue;
    int i = 0x12345678;
    double fp = 1.5; 
    char s[] = "this is a string"; 
    char c = '\n';  
    stream = fopen( "test.dat", "wb" ); 
    fprintf(stream, "%s%c\n", s, c); 
    fprintf(stream, "%x\n", i); 
    fprintf(stream, "%f\n", fp); 
    fclose(stream); 
    printf("hello world!\n");

    vectorTest();

#if 0
    filestream = fopen("new_file.log", "w" ); 
    if (argc < 3) {
        fprintf(filestream,"Usage: call pythonfile funcname [args]\n");
        return 1;
    }


    Py_Initialize();

    PyRun_SimpleString("import sys");  
    PyRun_SimpleString("sys.path.append('./')");  

    pName = PyUnicode_DecodeFSDefault(argv[1]);
    // Error checking of pName left out 

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);
    if(argc < 5)
    {
        //sprintf(filestream, )
        printf("argc < 5\n");
        if(pModule != NULL)
        {
            pFunc = PyObject_GetAttrString(pModule, argv[2]);
            /* pFunc is a new reference */

            if (pFunc && PyCallable_Check(pFunc))
            {
                printf("call pFunc\n");
                pValue = PyObject_CallObject(pFunc, NULL);
                if (pValue != NULL) 
                {
                    printf("Result of call: %ld\n", PyLong_AsLong(pValue));
                    Py_DECREF(pValue);
                }
                else 
                {
                    Py_DECREF(pFunc);
                    Py_DECREF(pModule);
                    PyErr_Print();
                    fprintf(filestream,"Call failed\n");
                    return 1;
                }
            }
            else
            {
                if (PyErr_Occurred())
                    PyErr_Print();
                fprintf(filestream, "Cannot find function \"%s\"\n", argv[2]);
            }
            Py_XDECREF(pFunc);
            Py_DECREF(pModule);

        }
        else
        {
            PyErr_Print();
            fprintf(filestream, "Failed to load \"%s\"\n", argv[1]);
            return 1;
        }
    }
    else
    {
        if(pModule != NULL)
        {
            pFunc = PyObject_GetAttrString(pModule, argv[2]);
            /* pFunc is a new reference */

            if (pFunc && PyCallable_Check(pFunc))
            {
                pArgs = PyTuple_New(argc - 3);
                for (i = 0; i < argc - 3; ++i) 
                {
                    pValue = PyLong_FromLong(atoi(argv[i + 3]));
                    if (!pValue)
                    {
                        Py_DECREF(pArgs);
                        Py_DECREF(pModule);
                        fprintf(stderr, "Cannot convert argument\n");
                        return 1;
                    }
                    /* pValue reference stolen here: */
                    PyTuple_SetItem(pArgs, i, pValue);
                }
                pValue = PyObject_CallObject(pFunc, pArgs);
                Py_DECREF(pArgs);
                if (pValue != NULL) 
                {
                    printf("Result of call: %ld\n", PyLong_AsLong(pValue));
                    Py_DECREF(pValue);
                }
                else 
                {
                    Py_DECREF(pFunc);
                    Py_DECREF(pModule);
                    PyErr_Print();
                    fprintf(filestream,"Call failed\n");
                    return 1;
                }
            }
            else
            {
                if (PyErr_Occurred())
                    PyErr_Print();
                fprintf(filestream, "Cannot find function \"%s\"\n", argv[2]);
            }
            Py_XDECREF(pFunc);
            Py_DECREF(pModule);
        }
        else
        {
            PyErr_Print();
            fprintf(filestream, "Failed to load \"%s\"\n", argv[1]);
            return 1;
        }
    }
    Py_Finalize();
#endif
    return 0;
}




