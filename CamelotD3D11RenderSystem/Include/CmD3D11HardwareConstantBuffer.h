#pragma once

#include "CmD3D11Prerequisites.h"
#include "CmD3D11HardwareBuffer.h"

// TODO - This isn't really used. Should be ported to D3D11GpuParamBlock

namespace CamelotEngine
{
	class CM_D3D11_EXPORT D3D11HardwareConstantBuffer
	{
	public:
		D3D11HardwareConstantBuffer(D3D11Device& device, HardwareBufferManagerBase* mgr, UINT32 sizeBytes, 
			GpuBufferUsage usage, bool useSystemMem);
		~D3D11HardwareConstantBuffer();

		/**
		 * @copydoc HardwareBuffer::readData
		 */
		void readData(UINT32 offset, UINT32 length, void* pDest);

		/**
		 * @copydoc HardwareBuffer::writeData
		 */
		void writeData(UINT32 offset, UINT32 length, const void* pSource,
			bool discardWholeBuffer = false);

		/**
		 * @copydoc HardwareBuffer::copyData
		 */
		void copyData(HardwareBuffer& srcBuffer, UINT32 srcOffset, UINT32 dstOffset, UINT32 length, bool discardWholeBuffer = false);

		/**
		 * @brief	Get the D3D-specific index buffer
		 */
		ID3D11Buffer* getD3DConstantBuffer() const { return mBuffer->getD3DBuffer(); }		

	protected:
		/**
		* @copydoc HardwareBuffer::lockImpl
		 */
		void* lockImpl(UINT32 offset, UINT32 length, GpuLockOptions options);

		/**
		 * @copydoc HardwareBuffer::unlockImpl
		 */
		void unlockImpl(void);

		D3D11HardwareBuffer* mBuffer;
	};
}