#include <bits/stdc++.h>

using namespace std;
#define repstl(iter, c) for(__typeof(c.begin()) iter = c.begin(); iter != c.end(); iter++)

map<int, int> p;
int f, s, t;

void augmentPath(int v int minEdge){
    if(v == s){
        f = minEdge;
        return;
    }
    else if(p.count(v)){
        augmentPath(p[v], min(minEdge,AdjMat[p[v][v]));
        AdjMat[p[v]][v] -= f;
        AdjMat[v][p[v]] += f;
    }
}

int main(){
    while(true){
        f = 0;

        queue<int> q;
        map<int, int> dist;
        q.push(s);
        dist[s] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u == t) break;

            repstl(v, AdjList[u]){
                if(AdjMat[u][v->first] > 0 && !dist.count(v->first)){
                    dist[v->first] = dist[u] + 1;
                    q.push(v->first);
                    p[v->first] = u;
                }
            }

            augumentPath(t, INF);
            if(f == 0) break;
            max_flow += f;
        }
    }
    printf("%d ",max_flow);
}













#include <windows.h>
#include <gl/gl.h>
#include <stdio.h>

#include "src/graphic.h"
#include "src/wndproc.h"
#include "src/draw.h"


#define SCREEN_WIDTH 512*3/2
#define SCREEN_HEIGHT 512*3/2

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    bool flagMLoop;

    WNDCLASSEX wc;
    HWND hwnd;
    MSG msg;

    HDC hDC;
    HGLRC hRC;

    //Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = CS_OWNDC;;
    wc.lpfnWndProc   = wndproc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = "windowClass1";
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc)){
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    //Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        wc.lpszClassName,
        "OpenGL",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        NULL, NULL,
        hInstance,
        NULL);

    if(hwnd == NULL){
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    EnableOpenGL(hwnd,&hDC,&hRC);
    draw_init();

    flagMLoop = true;

    while(flagMLoop){
        if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
            if(msg.message == WM_QUIT){
                flagMLoop = false;
            }else{
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }else{
            if(inputKeyboard['A']) printf("A!\n");
            if(inputKeyboard['Q']) DestroyWindow(hwnd);

            draw();
            SwapBuffers(hDC);

            Sleep(10);
        }
    }

    DisableOpenGL(hwnd, hDC, hRC);

    DestroyWindow(hwnd);

    return msg.wParam;
}
