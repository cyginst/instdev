#include "dll001.h"

#include "QtScript"


Dll001::Dll001()
{
}

extern "C"
DLL001SHARED_EXPORT int add2(int a, int b)
{
    return a + b;
}

//extern "C" {
//#define EXPORT_FUNCTION extern "C" __declspec(dllexport)
//} // extern "C"

#include <windows.h>
#include <stdio.h>
//#include <map>
//#include <mutex>
//#include <string>
#include <vector>
static void init_rundll_pg(std::vector<wchar_t *> &args)
{
    AllocConsole();
    freopen("CONIN$",  "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
    args.clear();
    LPWSTR *szArglist;
    int nArgs;
    szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
    for (int i = 1; i < nArgs; i++)
    {
        printf("%ls ", szArglist[i]);
        args.push_back(szArglist[i]);
    }
    printf("\n");
}
extern "C" __declspec(dllexport) void CALLBACK runServer(HWND hwnd, HINSTANCE hinst, const char * /*lpszCmdLine*/, int nCmdShow)
{
    Q_UNUSED(hwnd);
    Q_UNUSED(hinst);
    Q_UNUSED(nCmdShow);
    std::vector<wchar_t *> args;
    init_rundll_pg(args);
    int argc = 0;
    //system("pause");
    QCoreApplication app(argc, NULL);
    QScriptEngine engine;
    QString script("1+2"), result;
    result = engine.evaluate( script ).toString();
    qDebug() << "result=" << result;
    system("pause");
    return;
}
