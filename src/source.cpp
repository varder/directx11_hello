
#include <d3d11.h>
#include <iostream>
//#include <Windows.h>

LRESULT CALLBACK WinProc(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam) {
    if (msg == WM_DESTROY ||
        msg == WM_CLOSE) {
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(handle, msg, wparam, lparam);
}

class Renderer{
public:
    Renderer(HWND wnd){
         DXGI_SWAP_CHAIN_DESC swapChainDesc = {0};
         swapChainDesc.BufferCount = 1;
         swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
         swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
         swapChainDesc.OutputWindow = wnd;
         swapChainDesc.SampleDesc.Count = 1;
         swapChainDesc.Windowed = true;
         auto result = D3D11CreateDeviceAndSwapChain(
                        nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
                        nullptr, 0, D3D11_SDK_VERSION,
                        &swapChainDesc, &swapChain, &device, nullptr, &deviceContext
                     );


         if(result!=S_OK){
             MessageBox(nullptr, L"Eroor dx11 ", L"err", 0);
             exit(0);
         }

    }
    void clearRendererTarget(){
        ID3D11Texture2D *backBuffer;
        swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
        device->CreateRenderTargetView(backBuffer, nullptr, &rendertargetView);
        backBuffer->Release();
    }

    void beginFrame(){
        float rnd  = std::rand()%250;
        float color[] = {.25f, rnd/100, rnd/100., 1.};
        deviceContext->ClearRenderTargetView(rendertargetView, color);
    }

    void endFrame(){
        swapChain->Present(1,0);
    }

    IDXGISwapChain *swapChain = nullptr;
    ID3D11Device *device = nullptr;
    ID3D11DeviceContext *deviceContext = nullptr;
    ID3D11RenderTargetView *rendertargetView = nullptr;

};
#include <thread>
#include <chrono>

_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{

    WNDCLASS wc = { 0 };
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WinProc;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszClassName = L"DX11Tutorial";
    RegisterClass(&wc);

   HWND m_handle = CreateWindow(L"DX11Tutorial", L"C++11 and DX11 Tutorial",
        WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
        100, 100, 800, 600,
        nullptr, nullptr, nullptr, nullptr);

   Renderer rnd(m_handle);



   MSG msg = { 0 };
   while (true) {
       if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
//           TranslateMessage(&msg);
//           DispatchMessage(&msg);

//           if (msg.message == WM_QUIT) {
//               break;
//           }
           rnd.beginFrame();
           rnd.clearRendererTarget();
           std::this_thread::sleep_for(std::chrono::milliseconds(200));
           rnd.endFrame();
       }
   }


//    std::cin.get();

//    D3D12HelloWindow sample(1280, 720, L"D3D12 Hello Window");
        return 0;//sample.Run(hInstance, nCmdShow);
}



