#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

#define DXVK_WSI_SDL2 1
#include <d3d11.h>

int main(int argc, char** argv) {
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

  SDL_Window* window = SDL_CreateWindow("Poopie!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_VULKAN);

  ID3D11Device* device;
  ID3D11DeviceContext* ctx;
  IDXGISwapChain* swapchain;

  DXGI_SWAP_CHAIN_DESC sd = { };
  sd.BufferCount = 1;
  sd.BufferDesc.Width = 640;
  sd.BufferDesc.Height = 480;
  sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
  sd.BufferDesc.RefreshRate.Numerator = 60;
  sd.BufferDesc.RefreshRate.Denominator = 1;
  sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
  sd.OutputWindow = window;
  sd.SampleDesc.Count = 1;
  sd.SampleDesc.Quality = 0;
  sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
  sd.Windowed = FALSE;


  D3D_FEATURE_LEVEL level = D3D_FEATURE_LEVEL_11_0;
  D3D_FEATURE_LEVEL level2 = D3D_FEATURE_LEVEL_11_0;
  HRESULT hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, &level, 1, D3D11_SDK_VERSION, &sd, &swapchain, &device, &level2, &ctx);

  if (FAILED(hr)) {
    printf("frog");
    return 1;
  }

  printf("running");

  bool run = true;
  while (run) {
    SDL_Event evt;
    while (SDL_PollEvent(&evt)) {
      if (evt.type == SDL_QUIT)
        run = false;
    }

    swapchain->Present(0, 0);
  }

  SDL_Quit();

  return 0;
}