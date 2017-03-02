#include "DynArray.hh"

DynArray::DynArray(void) {
	m_capacity = DYN_ARRAY_DEFAULT_SIZE;
	m_size = 0;
	m_data = new int[m_capacity];//Apunta a la primera posicio de m_capacity
}


DynArray::DynArray(int *arr, size_t size) {
	m_capacity = DYN_ARRAY_DEFAULT_SIZE;
	m_size = 0;
	m_data = new int[m_capacity];


	for (int i = 0; i < m_capacity; i++) {
		m_data[i] = arr[i];
	}
}

DynArray::~DynArray(void) {
	delete[] m_data;
	m_data = nullptr;
}

DynArray& DynArray::operator=(const DynArray &x)
{
	DynArray z;
	z.capacity = x.capacity;
	for (int i = 0; i < m_capacity; i++) 
	{
		z.m_data[i] = x.m_data[i];
	}
}
