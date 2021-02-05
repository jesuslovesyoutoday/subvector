#include <iostream>

struct subvector {
    int *mas;                  //указатель на начало массива
    unsigned int top;          //размер массива (осознанные данные)
    unsigned int capacity;     //размер выделенной памяти
};


bool init(subvector *qv) //инициализирует пустой недовектор
{
    qv->mas = NULL;
    qv->top = 0;
    qv->capacity = 0;

    return 1;
};

bool push_back(subvector *qv, int d) //добавляет элемент в конец недовектора
{
    if ( qv->top >= qv->capacity )
    {
        int *p = new int [(qv->capacity)+10];
	if ((qv->mas)!=NULL)
	{
        	for ( int i = 0; i < qv->top; i++ )
        	{
            	p[i] = qv->mas[i];
        	}
  	}	
        delete[] qv->mas;
        qv->mas = p;
        qv->capacity += 10;
    }
    
    qv->mas[qv->top] = d;

    //std::cout << qv->top << "-----"  << qv->mas[qv->top] << std::endl;
    
    qv->top += 1;
    
    // std::cout << "Overflow len = " << qv->top << '\n';

    if (qv->mas[qv->top-1] == d)
    {
        return 1;
    }

    else
    {
        return 0;
    }
};

int pop_back(subvector *qv) //удаляет элемент с конца недовектора
{
    /*
    int *p = new int[qv->capacity]; --------- создает новый массив
    int a = qv->mas[qv->top];
    for ( int i = 0; i < qv->top; i ++)
    {
        p[i] = qv->mas[i];
    }
    delete[] qv->mas;
    qv->mas = p;
    qv->top -= 1;
    return a;
    */
    
    if ((qv->top)>0 & (qv->mas)!=NULL)
    {
	int curr = qv->mas[qv->top - 1]; 
    	qv->mas[qv->top - 1] = 0;
    	--(qv->top);
	return curr;
    }
    else
    {
	    return 0;
    }
};

bool resize(subvector *qv, unsigned int new_capacity) //увеличивает емкость недовектора
{
    int *p = new int[new_capacity];
    for ( int i = 0; i < qv->top; i ++ )
    {
        p[i] = qv->mas[i];
    }
    delete[] qv->mas;
    qv->mas = p;
    qv->capacity = new_capacity;

    if (qv->capacity == new_capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

void shrink_to_fit(subvector *qv) //очищает неиспользуемую память
{
    int *p = new int[qv->top];
    for ( int i = 0; i < qv->top; i++ )
    {
        p[i] = qv->mas[i];
    }
    delete[] qv->mas;
    qv->mas = p;
    qv->capacity = 0;
};

void clear(subvector *qv) //очищает содержимое недовектора
{
    int *p = new int[qv->capacity];
    delete[] qv->mas;
    qv->mas = p;
    qv->top = 0;
};

void destructor(subvector *qv)  //очищает всю используемую память, инициализирует недовектор как пустой
{
    delete[] qv->mas;
    
    init(qv);
};

void print_subvector(subvector *vec)
{
    for ( int i = 0; i < vec->top; i ++ )
    {
        std::cout << vec->mas[i] << ", ";
    }

    std::cout << std::endl;
} 
