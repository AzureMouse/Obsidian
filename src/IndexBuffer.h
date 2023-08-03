#pragma once
#include <cstdint>
class IndexBuffer {
private:
	uint32_t m_RendererID;
	uint32_t m_count;

public:
	// Default Constructor
	IndexBuffer(const void* data, uint32_t count);
	~IndexBuffer();

	void Bind();
	void Unbind();
};