#pragma once

#include <llarp.hpp>
#include "vpn_platform.hpp"

namespace llarp::apple
{
  struct Context : public llarp::Context
  {
    std::shared_ptr<vpn::Platform>
    makeVPNPlatform() override
    {
      return std::make_shared<VPNPlatform>(*this, m_PacketWriter, m_OnReadable);
    }

    // Callbacks that must be set for packet handling *before* calling Setup/Configure/Run; the main
    // point of these is to get passed through to VPNInterface, which will be called during setup,
    // after construction.
    VPNInterface::packet_write_callback m_PacketWriter;
    VPNInterface::on_readable_callback m_OnReadable;
  };

}  // namespace llarp::apple
