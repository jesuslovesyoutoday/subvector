#ifndef SUBVECTOR_IS_DEFINED
#define SUBVECTOR_IS_DEFINED

#include <iostream>

class subvector 
{
    public:
	subvector();
	bool push_back(int d);
	bool insert(int data, int place);
	int erase(int place);
	int get_element(int place);
	int pop_back();
	bool resize(unsigned int new_capacity);
	void shrink_to_fit();
	void clear();
	~subvector();
	void print_subvector();
	void unit_test();

    private:
	int *mas;                  //указатель на начало массива
    	unsigned int top;          //размер массива (осознанные данные)
    	unsigned int capacity;     //размер выделенной памяти
};

subvector::subvector() //инициализирует пустой недовектор
{
    this->mas = NULL;
    this->top = 0;
    this->capacity = 0;
}; 

bool subvector::insert(int data, int place) //добавляет элемент в произвольное место недовектора
{
	int *p = new int [(this->capacity) + 1];
	
	int i;
	
	for (i = 0; i < place; i++ )
	{
		p[i] = this->mas[i];
	} 
	
	p[i] = data;
	
	for (i = i + 1; i < this->top + 1; i ++)
	{
		p[i] = this->mas[i-1];
	}
	
	this->top ++;
	delete [] this->mas;
	this->mas = p;
	this->capacity ++;
	
	if (this->mas[place] == data)
	{
		return true;
	}
	
	else 
	{
		return false;
	}
}

int subvector::erase(int place)
{
	int *p = new int [this->capacity];
	int i;
	for (i = 0; i < place; i++)
	{
		p[i] = this->mas[i];
	}

	int a = mas[i];

	for (i = place + 1; i < this->top; i ++)
	{
		p[i] = this->mas[i+1];
	}
	
	this->top--;
	delete [] this->mas;
	this->mas = p;
	return a;
}

int subvector::get_element(int place)
{
	return this->mas[place];
}

bool subvector::push_back(int d) //добавляет элемент в конец недовектора
{
    if ( this->top >= this->capacity )
    {
        int *p = new int [(this->capacity)+10];
	if ((this->mas)!=NULL)
	{
        	for ( int i = 0; i < this->top; i++ )
        	{
            	p[i] = this->mas[i];
        	}
  	}	
        delete[] this->mas;
        this->mas = p;
        this->capacity += 10;
    }
    
    this->mas[this->top] = d;

    //std::cout << this->top << "-----"  << this->mas[this->top] << std::endl;
    
    this->top += 1;
    
    // std::cout << "Overflow len = " << this->top << '\n';

    if (this->mas[this->top-1] == d)
    {
        return 1;
    }

    else
    {
        return 0;
    }
};

int subvector::pop_back() //удаляет элемент с конца недовектора
{
    /*
    int *p = new int[this->capacity]; --------- создает новый массив
    int a = this->mas[qv->top];
    for ( int i = 0; i < this->top; i ++)
    {
        p[i] = this->mas[i];
    }
    delete[] this->mas;
    this->mas = p;
    this->top -= 1;
    return a;
    */
    
    if ((this->top)>0 & (this->mas)!=NULL)
    {
	int curr = this->mas[this->top - 1]; 
    	this->mas[this->top - 1] = 0;
    	--(this->top);
	return curr;
    }
    else
    {
	    return 0;
    }
};

bool subvector::resize(unsigned int new_capacity) //увеличивает емкость недовектора
{
    int *p = new int[new_capacity];
    for ( int i = 0; i < this->top; i ++ )
    {
        p[i] = this->mas[i];
    }
    delete[] this->mas;
    this->mas = p;
    this->capacity = new_capacity;

    if (this->capacity == new_capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

void subvector::shrink_to_fit() //очищает неиспользуемую память
{
    int *p = new int[this->top];
    for ( int i = 0; i < this->top; i++ )
    {
        p[i] = this->mas[i];
    }
    delete[] this->mas;
    this->mas = p;
    this->capacity = 0;
};

void subvector::clear() //очищает содержимое недовектора
{
    int *p = new int[this->capacity];
    delete[] this->mas;
    this->mas = p;
    this->top = 0;
};

subvector::~subvector()  //очищает всю используемую память
{
    delete[] this->mas;
};

void subvector::print_subvector()
{
    for ( int i = 0; i < this->top; i ++ )
    {
        std::cout << this->mas[i] << ", ";
    }

    std::cout << std::endl;
} 

void subvector::unit_test()
{
	int k = 0;

	this->push_back(1);
	this->push_back(2);
	this->push_back(3);
	
	if(this->pop_back()!=3)
	{
		std::cout << "push-pop test failed" << std::endl;
		k++;
	}
	
	this->push_back(3);
	this->resize(20);

	if(this->capacity!=20)
	{
		std::cout << "resize test failed" << std::endl;
		k++;
	}
	
	this->shrink_to_fit();

	if(this->capacity!=0)
	{
		std::cout << "fit test failed" << std::endl;
		k++;
	}

	this->clear();

	if(this->top != 0)
	{
		std::cout << "clear test failed" << std::endl;
		k++;
	}

	if(k==0)
	{
		std::cout << "All tests passed" << std::endl;
	}
}
#endif // SUBVECTOR_IS_DEFINED
