"""Windows process-memory metrics; explicitly unavailable elsewhere."""
import os
def memory():
    if os.name!='nt':
        return {'available':False,'reason':'Windows GetProcessMemoryInfo is unavailable on this OS; no memory estimate substituted.',
            'peak_working_set_bytes':None,'working_set_bytes':None,'peak_private_commit_bytes':None}
    import ctypes
    from ctypes import wintypes
    class PMC(ctypes.Structure):
        _fields_=[('cb',wintypes.DWORD),('PageFaultCount',wintypes.DWORD)]+[(n,ctypes.c_size_t) for n in
            ['PeakWorkingSetSize','WorkingSetSize','QuotaPeakPagedPoolUsage','QuotaPagedPoolUsage',
             'QuotaPeakNonPagedPoolUsage','QuotaNonPagedPoolUsage','PagefileUsage','PeakPagefileUsage']]
    info=PMC();info.cb=ctypes.sizeof(info)
    kernel=ctypes.WinDLL('kernel32',use_last_error=True);kernel.GetCurrentProcess.restype=wintypes.HANDLE
    psapi=ctypes.WinDLL('psapi',use_last_error=True)
    psapi.GetProcessMemoryInfo.argtypes=[wintypes.HANDLE,ctypes.POINTER(PMC),wintypes.DWORD]
    assert psapi.GetProcessMemoryInfo(kernel.GetCurrentProcess(),ctypes.byref(info),info.cb)
    return {'available':True,'peak_working_set_bytes':info.PeakWorkingSetSize,'working_set_bytes':info.WorkingSetSize,
        'peak_private_commit_bytes':info.PeakPagefileUsage}
