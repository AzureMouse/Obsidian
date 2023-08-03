#include <vector>
#include <GL/glew.h>

struct VertexBufferElement {
	uint32_t count;
	uint32_t type;
	bool normalized;
};

class VertexBufferLayout {
private:
	std::vector<VertexBufferElement> m_Elements;

public:
	VertexBufferLayout();

	template<typename T>
	void Push(int count) {
		static_assert(false);
	}

	template<>
	void Push(unsigned int count) {
		m_Elements.push_back({GL_FLOAT, count, false});
	}

	//template<>
	//void Push<unsigned char>(int count) {
		//m_Elements.push_back({ GL_UNSIGNED_BYTE, count, true });
	//}
};