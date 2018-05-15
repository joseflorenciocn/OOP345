#ifndef KVLIST_H
#define KVLIST_H

template <typename K, typename V, int N>

class KVList
{
public:

	//COnstructor
	KVList() : msize{ 0 } {}
	
	//Function to return the size of elements
	size_t size() const { return this->msize; }
	
	//Function to return the Key element
	const K& key(int i) const { return m_key[i]; }
	
	//Function to return the Value element
	const V& value(int i) const { return m_value[i]; }
	
	//Function to add elements
	KVList& add(const K& k, const V& v)
	{
		if (msize < N)
		{
			m_key[msize] = k;
			m_value[msize] = v;
			msize++;
		}

		return *this;
	}
	
	//Function to find the index of Key element, if didnt find
	// return index 0
	int find(const K& k) const
	{

		for (int t = 0; t < msize; t++)
		{
			if (this->m_key[t] == k) return t;
		}

		return 0;

		
	}
	
	//Function to replace elements in the object
	KVList& replace(int i, const K& k, const V& v)
	{
		this->m_key[i] = k;
		this->m_value[i] = v;

		return *this;

	}

private:
	K m_key[N];
	V m_value[N];
	int msize;

};


#endif

