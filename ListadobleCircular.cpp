#include <iostream>
using namespace std;

class nodo {
   public:
    nodo(int v)
    {
       valor = v;
       siguiente = NULL;
       anterior =NULL;
    }

nodo(int v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    int valor;
    nodo *siguiente;
    nodo *anterior;


   friend class listaD;
};

typedef nodo *pnodo;

class listaD {
   public:
    listaD() { primero = actual = NULL; }
    ~listaD();

    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void Siguiente();
    void Primero();
    void Ultimo();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();

   private:
    pnodo primero;
    pnodo actual;
};

listaD::~listaD()
{
   pnodo aux;

   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      if(primero->siguiente=primero){
        delete aux;
        actual = NULL;
        return;
      }
      delete aux;
   }
}

int listaD::largoLista(){
    int cont=0;

    pnodo aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux->siguiente!=primero){
        aux=aux->siguiente;
        cont++;
    }
    cont++;
    return cont;
    }

}

void listaD::InsertarInicio(int v)
{
   if (ListaVacia()){
     primero = new nodo(v);
     primero->siguiente=primero;
     primero->anterior=primero;}
   else
   {
     primero=new nodo (v,primero);
     primero->siguiente->anterior=primero;
     pnodo aux=primero->siguiente;
     while(aux->siguiente!=primero->siguiente)
        aux=aux->siguiente;
        aux->siguiente=primero;
        primero->anterior=aux;

   }
}

void listaD::InsertarFinal(int v)
{
   if (ListaVacia()){
     primero = new nodo(v);
     primero->siguiente=primero;
     primero->anterior=primero;}
   else
     { pnodo aux = primero;
        while ( aux->siguiente != primero)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
        aux->siguiente->anterior=aux;
        aux->siguiente->siguiente=primero;
        primero->anterior=aux->siguiente;
      }
}


void listaD::InsertarPos(int v,int pos)
{
   if (ListaVacia()){
     primero = new nodo(v);
     primero->siguiente=primero;
     primero->anterior=primero;}
   else{
        if(pos <=1)
          InsertarInicio(v);
        else
        {
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= primero)){
                   i++;
                   aux=aux->siguiente;
             }
             if(aux->siguiente==primero){
                InsertarFinal(v);
             }
             else{pnodo nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             aux->siguiente->anterior=aux;
             nuevo->siguiente->anterior=nuevo;}
        }
        }
}

void listaD::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;

   }else{
        if (primero->siguiente == primero) {
                primero= NULL;
            } else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != primero)
                {
                    aux = aux->siguiente;
                }

              pnodo temp = aux->siguiente;
              aux->siguiente= primero;
              primero->anterior=aux->siguiente;


                delete temp;
            }
        }
}

void listaD::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;

   }else{
        if (primero->siguiente == primero) {
                primero= NULL;
            } else {

                pnodo aux = primero;
                while(aux->siguiente!=primero)
                aux=aux->siguiente;
                aux->siguiente=primero->siguiente;
                aux->siguiente->anterior=aux;
                pnodo aux2=primero;
                primero=aux->siguiente;
                delete aux2;
            }
        }
}



void listaD:: borrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "Lista vacia" <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))
        {
        cout << "Error en posicion" << endl;
        }
        else
        {
        if(pos==1)
           BorrarInicio();
        else
        {
          if (pos == largoLista())
             BorrarFinal();
          else
          {
            int cont=2;
            pnodo aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodo temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}


void listaD::Mostrar()
{
   nodo *aux;

   aux = primero;
   while(aux->siguiente!=primero) {
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
   }
   cout << aux->valor << "-> ";
   cout << endl;
}

void listaD::Siguiente()
{
   if(actual) actual = actual->siguiente;
}

void listaD::Primero()
{
   actual = primero;
}

void listaD::Ultimo()
{
   actual = primero;
   if(!ListaVacia())
      while(actual->siguiente) Siguiente();
}

int main()
{
   listaD Lista;



   Lista.InsertarInicio(20);
   Lista.InsertarInicio(2);
   Lista.InsertarFinal(10);
   Lista.InsertarFinal(11);
   Lista.InsertarPos(5, 10);
   Lista.InsertarPos(6, 1);
   Lista.Mostrar();

   return 0;
}
