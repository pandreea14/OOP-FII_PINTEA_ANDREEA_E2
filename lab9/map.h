#pragma once
class MyIterator 
{
public:
	int* p;
	MyIterator& operator++() 
	{ 
		p++; 
		return *this; 
	}
	bool operator != (MyIterator& m) 
	{ 
		return p != m.p; 
	}
	int operator* () 
	{ 
		return *p; 
	}
};

template <typename K, typename V> 
class Map
{
	struct Pair
	{
		K key;
		V value;
		int index;
	};
	Pair* pairs;
	int currentIndex;
	int maxElements;
public:
	Map() 
	{
		this->maxElements = 10;
		this->currentIndex = 0;
		this->pairs = new Pair[this->maxElements];
	}

	MyIterator begin() 
	{
		MyIterator tmp; 
		tmp.p = &pairs[0].value;
		return tmp;
	}

	MyIterator end()
	{
		MyIterator tmp;
		tmp.p = &pairs[currentIndex].value;
		return tmp;
	}

	void Set(const K& key, const V& value)
	{
		for (int i = 0; i < currentIndex; i++)
		{
			if (pairs[i].key == key)
			{
				pairs[i].value = value;
				return;
			}
		}
		if (currentIndex == maxElements)
		{
			maxElements *= 2;
			Pair* newPairs = new Pair[maxElements];
			memcpy(newPairs, pairs, sizeof(Pair) * currentIndex);
			delete[] pairs;
			pairs = newPairs;
		}

		pairs[currentIndex].key = key;
		pairs[currentIndex].value = value;
		pairs[currentIndex].index = currentIndex;
		currentIndex++;
	}

	bool Get(const K& key, V& value)//daca exista cheia key va fi copiata valoarea sa asociata in variabila value
	{
		for (int i = 0; i < currentIndex; i++)
		{
			if (pairs[i].key == key)
			{
				value = pairs[i].value;
				return true;
			}
		}
		return false;
	}

	int Clear()
	{
		currentIndex = 0;
	}

	int Count()
	{
		return currentIndex;
	}

	bool Includes(const Map<K,V>& map)
	{
		for (int i = 0; i < map.currentIndex; i++)
		{
			bool found = false;
			for (int j = 0; j < currentIndex; j++) 
			{
				if (map.pairs[i].key == pairs[j].key) 
				{
					found = true;
					break;
				}
			}
			if (!found) 
			{
				return false;
			}
		}
		return true;
	}

	bool Delete(const K& key)
	{
		for (int i = 0; i < currentIndex; i++)
		{
			if (pairs[i].key == key)
			{
				for (int j = i; j < currentIndex - 1; j++)//stergere normala din vector	
				{
					pairs[j] = pairs[j + 1];
				}
				currentIndex--;
				return true;
			}
		}
		return false;
	}

	V& operator[] (const K& key)
	{
		for (int i=0; i < currentIndex; i++)
		{
			if (pairs[i].key == key)
			{
				return pairs[i].value;
			}
		}
		if (currentIndex < maxElements)
		{
			pairs[currentIndex].key = key;
			pairs[currentIndex].index = currentIndex;
			currentIndex++;
			return pairs[currentIndex - 1].value;
		}
		throw "Map is full";
	}


};