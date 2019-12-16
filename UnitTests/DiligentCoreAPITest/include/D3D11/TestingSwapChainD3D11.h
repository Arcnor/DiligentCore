/*     Copyright 2019 Diligent Graphics LLC
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF ANY PROPRIETARY RIGHTS.
 *
 *  In no event and under no legal theory, whether in tort (including negligence), 
 *  contract, or otherwise, unless required by applicable law (such as deliberate 
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental, 
 *  or consequential damages of any character arising as a result of this License or 
 *  out of the use or inability to use the software (including but not limited to damages 
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and 
 *  all other commercial damages or losses), even if such Contributor has been advised 
 *  of the possibility of such damages.
 */

#include "TestingSwapChainBase.h"

#ifndef NOMINMAX
#    define NOMINMAX
#endif

#include <d3d11.h>
#include <atlcomcli.h>

namespace Diligent
{

namespace Testing
{

class TestingSwapChainD3D11 final : public TestingSwapChainBase<ISwapChain>
{
public:
    using TBase = TestingSwapChainBase<ISwapChain>;
    TestingSwapChainD3D11(IReferenceCounters*  pRefCounters,
                          IRenderDevice*       pDevice,
                          IDeviceContext*      pContext,
                          const SwapChainDesc& SCDesc);

    virtual void TakeSnapshot() override final;

    ID3D11Texture2D* GetD3D11RenderTarget()
    {
        return m_pd3d11RenderTarget;
    }

    ID3D11Texture2D* GetD3D11DepthBuffer()
    {
        return m_pd3d11DepthBuffer;
    }

    ID3D11RenderTargetView* GetD3D11RTV()
    {
        return m_pd3d11RTV;
    }

    ID3D11DepthStencilView* GetD3D11DSV()
    {
        return m_pd3d11DSV;
    }

private:
    CComPtr<ID3D11DeviceContext>    m_pd3d11Context;
    CComPtr<ID3D11Texture2D>        m_pd3d11RenderTarget;
    CComPtr<ID3D11Texture2D>        m_pd3d11DepthBuffer;
    CComPtr<ID3D11RenderTargetView> m_pd3d11RTV;
    CComPtr<ID3D11DepthStencilView> m_pd3d11DSV;
    CComPtr<ID3D11Texture2D>        m_pd3d11StagingTex;
};

} // namespace Testing

} // namespace Diligent
