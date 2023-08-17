#include <Python.h>

float fastInvSqrt(float x) {
  float half = 0.5f * x;
  int i = *(int*)&x;         // evil floating point bit level hacking
  i = 0x5f3759df - (i >> 1);  // what the fuck?
  x = *(float*)&i;
  x = x*(1.5f-(half*x*x));
  return x;
}

// python implementation
static PyObject *method_fast_inv_sqrt(PyObject *self, PyObject *args) {
    float initial = 1.0f;
    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "f", &initial)) {
        return NULL;
    }
    float result = fastInvSqrt(initial);
    return PyFloat_FromDouble((double) result);
}


// define the module and description
static PyMethodDef FastInvSqrtMethods[] = {
    {"fast_inv_sqrt", method_fast_inv_sqrt, METH_VARARGS, "fast_inv_sqrt implementation in C"},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef fast_inv_sqrt_module = {
    PyModuleDef_HEAD_INIT,
    "fast_inv_sqrt",
    "fast_inv_sqrt implementation in C",
    -1,
    FastInvSqrtMethods
};

// init the module
PyMODINIT_FUNC PyInit_fast_inv_sqrt(void) {
    return PyModule_Create(&fast_inv_sqrt_module);
}