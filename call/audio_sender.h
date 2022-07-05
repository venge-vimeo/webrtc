/*
 *  Copyright (c) 2020 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef CALL_AUDIO_SENDER_H_
#define CALL_AUDIO_SENDER_H_

#include <memory>

#include "api/audio/audio_frame.h"
#include "modules/audio_coding/include/audio_coding_module_typedefs.h"

namespace webrtc {

class AudioSender {
 public:
  // Encode and send audio.
  virtual void SendAudioData(std::unique_ptr<AudioFrame> audio_frame) = 0;
  virtual void SendAudioData(AudioFrameType frameType,
                             uint8_t payloadType,
                             uint32_t rtp_timestamp,
                             const uint8_t* payloadData,
                             size_t payloadSize,
                             int64_t absolute_capture_timestamp_ms) = 0;

  virtual ~AudioSender() = default;
};

}  // namespace webrtc

#endif  // CALL_AUDIO_SENDER_H_
