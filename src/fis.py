import struct

def fast_inv_sqrt_py(x:float)->float:
    """
    fast inverse square root implementation on python

    >>> fast_inv_sqrt_py(9)
    0.03333
    """
    half = 0.5 * x
    i = struct.unpack('!I', struct.pack('!f', x))[0]
    i = 0x5f3759df - (i >> 1)
    x = struct.unpack('!f', struct.pack('!I', i))[0]
    x = x * (1.5 - (half * x * x))
    return x