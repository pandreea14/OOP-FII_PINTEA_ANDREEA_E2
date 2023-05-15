#pragma once
#include <iostream>
#include <exception>
using namespace std;

class exceptie1 : public exception
{
    virtual const char* what() const throw()
    {
        return "Index out of range!";
    }
};

class exceptie2 : public exception
{
    virtual const char* what() const throw()
    {
        return "Index does not exist";
    }
};

class exceptie3 : public exception
{
    virtual const char* what() const throw()
    {
        return "Array is full";
    }
};

class exceptie4 : public exception
{
    virtual const char* what() const throw()
    {
        return "Item already exists";
    }
};

/*
class Compare 
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
*/

template<class T>
class ArrayIterator 
{
    T* current;
public:
    ArrayIterator(T* ptr) : current(ptr) {}

    T& operator*() const {
        return *current;
    }

    ArrayIterator<T>& operator++() {
        ++current;
        return *this;
    }

    ArrayIterator<T> operator++(int) {
        ArrayIterator<T> temp = *this;
        ++current;
        return temp;
    }

    bool operator==(const ArrayIterator<T>& other) const {
        return current == other.current;
    }

    bool operator!=(const ArrayIterator<T>& other) const {
        return !(*this == other);
    }
};

template<class T>
class Array
{
private:
    T** List;
    int Capacity;
    int Size;

    exceptie1 outofrange;
    exceptie2 array_full;

public:
    Array() 
    {
        this->List = new T * [0];
        this->Capacity = 0;
        this->Size = 0;
    }
    ~Array()
    {
        for (int i = 0; i < Size; i++)
        {
            delete this->List[i];
            this->List[i] = nullptr;
        }
        delete[] this->List;
    }
    Array(int capacity) 
    {
        this->List = new T * [capacity];
        this->Capacity = capacity;
        this->Size = 0;
        int i = 0;
        while (i < this->Capacity) 
        {
            this->List[i] = nullptr;
            ++i;
        }
    }
    //copy constr
    Array(const Array<T>& otherArray)
    {
        this->List = new T[otherArray.Capacity];
        this->Capacity = otherArray.Capacity;
        this->Size = otherArray.Size;

        for (int i = 0; i < Size; i++)
        {
            this->List[i] = new T(*otherArray.List[i]);
        }
    }
    T& operator[] (int index)
    {
        exceptie1 oor;
        exceptie2 inotex;
        try 
        {
            if (index < 0 || index >= Size)
            {
                throw oor;
            }
            if (this->List[index] == nullptr) {
                throw inotex;
            }
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }
        return this->List[index];
    }
    Array<T>& operator+= (const T& newElem)
    {
        exceptie3 af;
        try 
        {
            if (Size == Capacity)
            {
                throw af;
            }
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            return *this;
        }
        List[Size++] = new T(newElem);
        return *this;
    }
    void Sort() 
    {
        T* aux;
        int j;
        for (int i = 0; i < this->Capacity - 1; i++)
        {
            for (int j = i + 1; j < this->Capacity; j++) 
            {
                if (this->List[i] != nullptr && this->List[j] != nullptr)
                {
                    aux = this->List[i];
                    this->List[i] = this->List[j];
                    this->List[j] = aux;
                    aux = nullptr;
                }
            }
        }
    }

    void Sort(bool(*compare)(const T&, const T&)) 
    {
        T* aux;
        int j;
        for (int i = 0; i < this->Capacity - 1; i++)
        {
            for (int j = i + 1; j < this->Capacity; j++)
            {
                if (this->List[i] != nullptr && this->List[j] != nullptr && compare(*(this->List[i]), *(this->List[j])))
                {
                    aux = this->List[i];
                    this->List[i] = this->List[j];
                    this->List[j] = aux;
                    aux = nullptr;
                }
            }
        }
    }

    Array<T>& Insert(int index, const T& newElem) 
    {
        exceptie1 oor;
        exceptie3 af;
        exceptie4 alreadyexists;
        try 
        {
            if (index < 0 || index >= this->Size)
            {
                throw oor;
            }
            if (this->Size == this->Capacity) {
                throw af;
            }
            if (this->List[index] != nullptr) {
                throw alreadyexists;
            }
        }
        catch (exception& ex) 
        {
            cout << "Exception: " << ex.what() << endl;
            return *this;
        }
        this->List[index] = new T(newElem);
        this->Size++;
        return *this;
    }

    const Array<T>& Delete(int index) 
    {
        exceptie1 oor;
        exceptie2 notexist;
        exceptie4 alreadyexists;
        try 
        {
            if (index >= this->Capacity) 
            {
                throw oor;
            }
            if (this->Size == 0) 
            {
                throw alreadyexists;
            }
            if (this->List[index] == nullptr)
            {
                throw notexist;
            }
        }
        catch (exception& ex) 
        {
            cout << "Exception: " << ex.what() << endl;
            return *this;
        }
        delete this->List[index];
        this->List[index] = nullptr;
        this->Size--;
        return *this;
    }
  
    int GetSize() const
    {
        return Size;
    }
    int GetCapacity() const
    {
        return Capacity;
    }
    bool IsEmpty() const
    {
        return Size == 0;
    }
    void Clear()
    {
        for (int i = 0; i < Size; i++)
        {
            delete List[i];
        }
        delete[] List;
        List = nullptr;
        Size = 0;
        Capacity = 0;
    }
    ArrayIterator<T> begin()
    {
        ArrayIterator<T> iter;
        return iter;
    }
    ArrayIterator<T> end()
    {
        ArrayIterator<T> iter;
        iter = Size;
        return iter;
    }
};

/*
template<class T>
class Array 
{
private:
    T** List;
    int Capacity;
    int Size;
public:
    Array() 
    {
        List = NULL;
        Capacity = 0;
        Size = 0;
    }
    ~Array() 
    {
        if (List!=NULL) 
        {
            for (int i = 0; i < Size; i++) 
            {
                delete List[i];
            }
            delete[] List;
            List = NULL;
            Capacity = 0;
            Size = 0;
        }
    }
    Array(int capacity) 
    {
        List = new T * [capacity];
        Capacity = capacity;
        Size = 0;
    }
    Array(const Array<T>& otherArray) 
    {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++) 
        {
            List[i] = new T(*otherArray.List[i]);
        }
    }
    T& operator[] (int index) 
    {
        if (index < 0 || index >= Size) 
        {
            throw out_of_range("Index out of range");
        }
        return *List[index];
    }
    const Array<T>& operator+=(const T& newElem) 
    {
        if (Size == Capacity) 
        {
            throw runtime_error("Array is full");
        }
        List[Size++] = new T(newElem);
        return *this;
    }
    const Array<T>& Insert(int index, const T& newElem) 
    {
        if (index < 0 || index >= Size) 
        {
            throw out_of_range("Index out of range");
        }
        if (Size == Capacity) 
        {
            throw runtime_error("Array is full");
        }
        for (int i = Size; i > index; i--) 
        {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> otherArray) 
    {
        if (index < 0 || index >= Size) 
        {
            throw out_of_range("Index out of range");
        }
        if (Size + otherArray.Size > Capacity) 
        {
            throw runtime_error("Array is full");
        }
        for (int i = Size - 1; i >= index; i--) 
        {
            List[i + otherArray.Size] = List[i];
        }
        for (int i = 0; i < otherArray.Size; i++) 
        {
            List[index + i] = new T(*otherArray.List[i]);
        }
        Size += otherArray.Size;
        return *this;
    }
    const Array<T>& Delete(int index) 
    {
        if (index < 0 || index >= Size) 
        {
            throw out_of_range("Index out of range");
        }
        delete List[index];
        for (int i = index + 1; i < Size; i++) 
        {
            List[i - 1] = List[i];
        }
        Size--;
        return *this;
    }

	bool operator=(const Array<T>& otherArray);

	void Sort(); // sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
	void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator



	int Find(const T& elem); // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie

	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator



	int GetSize();

	int GetCapacity();



	ArrayIterator<T> GetBeginIterator();

	ArrayIterator<T> GetEndIterator();

};*/
