#include "DynArray.h"


// Constructors
DynArray::DynArray(void) : //POR DEFECTO SIN ARGUMENTOS
	m_capacity{ DYN_ARRAY_DEFAULT_SIZE },
	m_size{ 0 },
	m_data{ new int[DYN_ARRAY_DEFAULT_SIZE] }
{};
DynArray::DynArray(size_t size, const int &value) : // DECALRA UNA ARRAY DE N ELEMENTOS I LOS INICIALIZA EN UN VALOR
	m_capacity{ size }, m_size{ size }, m_data{ new int[size] }
{
	fill(begin(), end(), value);
};
DynArray::DynArray(int *arr, size_t size) :
	m_capacity(size),
	m_size(size),
	m_data(new int[size])
{

};

// Destructor
DynArray :: ~DynArray(void)
{
	delete[] m_data;
	m_data = nullptr;
}

//Asignar operadores
DynArray&  DynArray :: operator= (const DynArray &x)
{
	m_capacity = x.m_capacity;
	m_size = x.m_size;

	delete[] m_data;
	m_data = new int[m_capacity];
	for (int i{ 0 }; i < m_size; i++)
	{
		m_data[i] = x.m_data[i];
	}

	return *this;
}

//Metodos
int* DynArray::begin(void) const		// DIRECION DEL PRIMER ELEMENTO DE LA ARRAY
{
	return m_data;
}
int* DynArray::end(void) const		// DIRECCION DEL ULTIMO ELEMENTO DE LA ARRAY
{
	return m_data + m_size;
}

// Modificar Metodos
void DynArray::push(const int &val)
{

	if (m_size == m_capacity)
	{
		int *tmp = new int[m_capacity += m_size / 2]; // RESERVA UN NUEVO ESPACIO CON LA CAPACIDAD QUE TENIA +1

													  // COPIAR LOS ELEMENTOS QUE YA TENIA AL NUEVO ESPACIO GUARDADO
		for (int i{ 0 }; i < m_size; i++)
		{
			tmp[i] = m_data[i];
		}

		delete[] m_data;
		m_data = tmp;
	}
	m_data[m_size] = val;
	m_size++;
}


bool operator== (const DynArray& lhs, const DynArray& rhs)	// checks if 2 arrays are equal (AL SER FRIEND; PUEDE ACCEDER A LOS ATRIBUTOS PRIVADOS DE LA ARRAY)
{
	if (lhs.m_size != rhs.m_size)
	{
		return false;
	}

	for (int i{ 0 }; i < lhs.m_size; i++)
	{
		if (
			lhs.m_data[i] != rhs.m_data[i])
		{
			return false;
		}
	}
	return true;
}


void DynArray::fill(int *first, int *last, int value) // assigns the given value to the elements in the range [first, last)
{
	while (first != last)
	{
		*first = value;
		first++;
	}
}