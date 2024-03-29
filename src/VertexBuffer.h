#pragma once
#include <cstdint>
class VertexBuffer {
private:
	uint32_t m_RendererID;

public:
	// Default Constructor
	VertexBuffer(const void* data, uint32_t size);
	~VertexBuffer();

	void Bind();
	void Unbind();
};