#include "pDataConverter.h"
#include "usbd_def.h"
/**
  * @brief  USBD_AUDIO_DataOut
  *         handle data OUT Stage
  * @param  pdev: device instance
  * @param  epnum: endpoint index
  * @retval status
  */
typedef  union UN32_ {
	uint8_t b[4];
	int32_t s;
} UN32;

// incoming USB audio data buffer : uint8_t array
// Each 24bit stereo sample is encoded as : L channel 3bytes + R channel 3bytes, LSbyte first
// b0:lo_L, b1:mid_L, b2:hi_L, b3:lo_R, b4:mid_R, b5:hi_R

// volume control is implemented by scaling the data, attenuation resolution is 3dB.
// 6dB is equivalent to a shift right by 1 bit.

// outgoing I2S Philips data format is : left-aligned 24bits in 32bit frame, MSbyte first
// STM32 I2S peripheral uses a 16bit data register
// => outgoing I2S transmit data buffer : uint16_t array
// Each I2S stereo sample is encoded as {hi_L:mid_L}, {lo_L:0x00}, {hi_R:mid_R}, {lo_R:0x00}
static uint8_t USBD_AUDIO_DataOut(USBD_HandleTypeDef* pdev,  uint8_t epnum){
    /*
	USBD_AUDIO_HandleTypeDef* haudio;
	haudio = (USBD_AUDIO_HandleTypeDef*)pdev->pClassData;

	static uint8_t tmpbuf[1024];

	if (all_ready == 1U && epnum == AUDIO_OUT_EP) {
		uint32_t curr_length = USBD_GetRxCount(pdev, epnum);
		// Ignore strangely large packets
		if (curr_length > AUDIO_OUT_PACKET_24B) {
			curr_length = 0U;
			}

		uint32_t tmpbuf_ptr = 0U;
		uint32_t num_samples = curr_length / 6; // 3bytes per sample

		for (int i = 0; i < num_samples; i++) {
			UN32 sample;
			sample.b[0] = tmpbuf[tmpbuf_ptr]; // lsb
			sample.b[1] = tmpbuf[tmpbuf_ptr+1];
			sample.b[2] = tmpbuf[tmpbuf_ptr+2]; // msb
			sample.b[3] = sample.b[2] & 0x80 ? 0xFF : 0x00; // sign extend to 32bits
			sample.s = USBD_AUDIO_Volume_Ctrl(sample.s,haudio->vol_3dB_shift);

			haudio->buffer[haudio->wr_ptr++] = (((uint16_t)sample.b[2]) << 8) | (uint16_t)sample.b[1];
			haudio->buffer[haudio->wr_ptr++] = ((uint16_t)sample.b[0]) << 8;

			sample.b[0] = tmpbuf[tmpbuf_ptr+3]; // lsb
			sample.b[1] = tmpbuf[tmpbuf_ptr+4];
			sample.b[2] = tmpbuf[tmpbuf_ptr+5]; // msb
			sample.b[3] = sample.b[2] & 0x80 ? 0xFF : 0x00; // sign extend to 32bits

			sample.s = USBD_AUDIO_Volume_Ctrl(sample.s,haudio->vol_3dB_shift);

			haudio->buffer[haudio->wr_ptr++] = (((uint16_t)sample.b[2]) << 8) | (uint16_t)sample.b[1];
			haudio->buffer[haudio->wr_ptr++] = ((uint16_t)sample.b[0]) << 8;

			tmpbuf_ptr += 6;

			// Rollover at end of buffer
			if (haudio->wr_ptr >= AUDIO_TOTAL_BUF_SIZE) {
				haudio->wr_ptr = 0U;
				}
			}

		// Start playing when half of the audio buffer is filled
		// so if you increase the buffer length too much, the audio latency will be obvious when watching video+audio
		if (haudio->offset == AUDIO_OFFSET_UNKNOWN && is_playing == 0U) {
			if (haudio->wr_ptr >= AUDIO_TOTAL_BUF_SIZE / 2U) {
				haudio->offset = AUDIO_OFFSET_NONE;
				is_playing = 1U;

				if (haudio->rd_enable == 0U) {
					haudio->rd_enable = 1U;
					// Set last writable buffer size to actual value. Note that rd_ptr is 0 now.
					audio_buf_writable_samples_last = (AUDIO_TOTAL_BUF_SIZE - haudio->wr_ptr)/6;
					}

				((USBD_AUDIO_ItfTypeDef*)pdev->pUserData)->AudioCmd(&haudio->buffer[0], AUDIO_TOTAL_BUF_SIZE * 2, AUDIO_CMD_START);
				}
			}

		USBD_LL_PrepareReceive(pdev, AUDIO_OUT_EP, tmpbuf, AUDIO_OUT_PACKET_24B);
		}
*/
	return USBD_OK;
}
