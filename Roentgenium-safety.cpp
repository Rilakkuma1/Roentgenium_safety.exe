#include <windows.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "kernel32.lib")
//externing rtladjustprivilege
EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
//externing ntraiseharderror
EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask, PULONG_PTR Parameters, ULONG ValidRespnseOption, PULONG Response);

static ULONGLONG n, r;
int randy() { return n = r, n ^= 0x8ebf635bee3c6d25, n ^= n << 5 | n >> 26, n *= 0xf3e05ca5c43e376b, r = n, n & 0x7fffffff; }

DWORD WINAPI shader1(LPVOID lpParam) {
    int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm, w * h * 4, data);
        int v = 0;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 60000)
            byte = randy() % 0xff;
        for (int i = 0; w * h > i; i++) {
            if (i % h == 0 && randy() % 110)
                v = randy() % 25;
            ((BYTE*)(data + i))[v * v] = ((BYTE*)(data + i + v))[v];
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);
        DeleteObject(desk);
    }
    return 0;
}
DWORD WINAPI shader2(LPVOID lpParam) {
    int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm, w * h * 4, data);
        int v = 0;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 60000)
            byte = randy() % 0xff;
        for (int i = 0; w * h > i; i++) {
            if (i % h == 0 && randy() % 100 == 0)
                v = randy() % 50;
            ((BYTE*)(data + i))[v % 3] += ((BYTE*)(data + i + v))[v] ^ byte;
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);
        DeleteObject(desk);
    }
    return 0;
}
DWORD WINAPI jpg(LPVOID lpParam) {
    HDC hdc = GetDC(HWND_DESKTOP);
    int X = GetSystemMetrics(SM_CXSCREEN);
    int Y = GetSystemMetrics(SM_CYSCREEN);

    while (TRUE)
    {
        HDC hdc = GetDC(HWND_DESKTOP);
        int X = GetSystemMetrics(SM_CXSCREEN);
        int Y = GetSystemMetrics(SM_CYSCREEN);
        BitBlt(hdc, rand() % (X - 0), rand() % (Y - 0), rand() % (X - 0), rand() % (Y - 0), hdc, rand() % (X - 0), rand() % (Y - 0), PATINVERT);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI ico(LPVOID lpParam) {
    HDC desk;
    int sw, sh;

    while (1) {
        desk = GetDC(0);
        sw = GetSystemMetrics(0);
        sh = GetSystemMetrics(1);
        StretchBlt(desk, 0, -20, sw, sh + 40, desk, 0, 0, sw, sh, SRCCOPY);
        ReleaseDC(0, desk);
        Sleep(100);
    }
}

DWORD WINAPI shader3(LPVOID lpParam) {
    int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm, w * h * 4, data);
        int v = 0;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 60000)
            byte = randy() % 0xff;
        for (int i = 0; w * h > i; i++) {
            if (i % h == 0 && randy() % 110)
                v = randy() % 32;
            ((BYTE*)(data + i))[v * 10] = ((BYTE*)(data + i + v))[v];
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);
        DeleteObject(desk);
    }
    return 0;
}
DWORD WINAPI shader4(LPVOID lpParam) {
    int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCCOPY);
        GetBitmapBits(hbm, w * h * 4, data);
        int v = 0;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 60000)
            byte = randy() % 0xff;
        for (int i = 0; w * h > i; i++) {
            if (i % h == 0 && randy() % 110)
                v = randy() % 32;
            ((BYTE*)(data + i))[0] = ((BYTE*)(data + i + v))[0];
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCCOPY);
        DeleteObject(hbm);
        DeleteObject(hdcdc);
        DeleteObject(desk);
    }
    return 0;
}
DWORD WINAPI hell1(LPVOID lpParam)
{
    HDC hdc = GetDC(0);
    int x = GetSystemMetrics(0);
    int y = GetSystemMetrics(1);

    while (1)
    {
        hdc = GetDC(0);
        BitBlt(hdc, 0, 2 + rand(), x, y, hdc, 0, -2 + rand(), 0x999999);
        BitBlt(hdc, 0, -2 + rand(), x, y, hdc, 0, 2 + rand(), 0x999999);
        ReleaseDC(0, hdc);
    }
}
VOID WINAPI sound1() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>((-t & 4095) * (255 & t * (t & t >> 13)) >> 12) + (127 & t * (234 & t >> 8 & t >> 3) >> (3 & t >> 14));

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI sound2() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t >> 9 ^ (t >> 9) - 1 ^ 1) % 13 * t;

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI sound5() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t >> 9 & 2 * t & 10 * t | t >> 5 & 6 * t);

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI sound6() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(t * (t & 16384 ? 6 : 5) * (1 + (3 & t >> 10)) >> (3 & t >> 8) | t >> 2);

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
VOID WINAPI sound7() {
    HWAVEOUT hWaveOut = 0;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    char buffer[8000 * 30] = {};
    for (DWORD t = 0; t < sizeof(buffer); ++t)
        buffer[t] = static_cast<char>(20 * t * t * (t >> 11) / 7);

    WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
    waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
}
int main() {
    if (MessageBoxW(NULL, L".", L"Roentgenium-safety.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
    {
        ExitProcess(0);
    }
    else {
        if (MessageBoxW(NULL, L"..", L"Roentgenium-safety.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
        {
            ExitProcess(0);
        }
        else {
            if (MessageBoxW(NULL, L"...", L"Roentgenium-safety.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
            {
                ExitProcess(0);
            }
            else {
                if (MessageBoxW(NULL, L"Are you sure", L"Roentgenium-safety.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
                {
                    ExitProcess(0);
                }
                else {
                    sound1();
                    HANDLE thread1 = CreateThread(0, 0, shader1, 0, 0, 0);
                    Sleep(30000);
                    TerminateThread(thread1, 0);
                    CloseHandle(thread1);
                    InvalidateRect(0, 0, 0);
                    Sleep(1000);
                    HANDLE thread2 = CreateThread(0, 0, shader2, 0, 0, 0);
                    sound2();
                    Sleep(30000);
                    TerminateThread(thread2, 0);
                    CloseHandle(thread2);
                    InvalidateRect(0, 0, 0);
                    Sleep(1000);
                    HANDLE thread3 = CreateThread(0, 0, jpg, 0, 0, 0);
                    PlaySoundW(L"sound3.wav", NULL, SND_FILENAME | SND_ASYNC);
                    Sleep(30000);
                    TerminateThread(thread3, 0);
                    CloseHandle(thread3);
                    InvalidateRect(0, 0, 0);
                    Sleep(1000);
                    HANDLE thread4 = CreateThread(0, 0, ico, 0, 0, 0);
                    PlaySoundW(L"sound4.wav", NULL, SND_FILENAME | SND_ASYNC);
                    Sleep(30000);
                    TerminateThread(thread4, 0);
                    CloseHandle(thread4);
                    InvalidateRect(0, 0, 0);
                    Sleep(1000);
                    HANDLE thread5 = CreateThread(0, 0, shader3, 0, 0, 0);
                    sound5();
                    Sleep(30000);
                    TerminateThread(thread5, 0);
                    CloseHandle(thread5);
                    InvalidateRect(0, 0, 0);
                    Sleep(1000);
                    HANDLE thread6 = CreateThread(0, 0, shader4, 0, 0, 0);
                    sound6();
                    Sleep(30000);
                    TerminateThread(thread6, 0);
                    CloseHandle(thread6);
                    InvalidateRect(0, 0, 0);
                    Sleep(1000);
                    HANDLE thread7 = CreateThread(0, 0, hell1, 0, 0, 0);
                    sound7();
                    Sleep(30000);
                    // Exit the program
                    ExitProcess(0);
                }
            }
        }
    }
}

