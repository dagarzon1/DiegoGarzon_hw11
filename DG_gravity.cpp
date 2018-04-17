#include<iostream>

using namespace std;

double fun_v(double x,double a, double v);
double fun_x(double x, double a, double v);
void segundo_orden( int a, double in, double in_d, double h);
int main()
{	
	//Variable iniciales
	double m=10, x_in=3, v_in=200, h=0.1;
	//Funcion que calcula ecuaciones diferencial de segundo orden por Runge-Kutta
	segundo_orden(0.0,x_in,v_in,h);
	return 0;
	
}
//Funcion que establece la funcion de velocidad correspondiente a la ecuacion diferencial
double fun_v(double x)
{	
	//Constantes presentes en la ecuacion diferencial
	double G=10.0;
	double M=1000.0;
	//funcion referente al cambio de velocidad en terminos de la fuerza gravitatoria
	double res= (-1.0) * G * M / (x*x);
	return res;
}
//Funcion que establece la primera derivada de la posicion en funcion del tiempo
double fun_x( double v)
{
	return v;
}
////Funcion que calcula ecuaciones diferencial de segundo orden por Runge-Kutta
void segundo_orden(int a, double in, double in_d, double h)
{
	//Distancia maxima que se le va a permitir a la particula ir
	double dist_max=0.01*a;
	//Variable que simula el tiempo
	double t=a;
	//Variable que simula la velocidad
	double v=in;
	//Variable que simula la posicion
	double y=in_d;
	//Impresion de los valores inciales
	cout << y << " " << v << " " << t << endl;
	//
	double zk_1,zk_2,zk_3,zk_4;
	double k_1,k_2,k_3,k_4;
	//Centinela para detener el ciclo cuando se llegue a la distancia maxima
	bool centinela=true;
	//Ciclo que estima el cambio en las funciones
	while(centinela)
	{
		//Avance en el tiempo
		t=t+h;

		//variables de Runge-Kutta para las variables de posicion y velocidad
		zk_1=fun_v( y );
		k_1=fun_x( v );
		
		zk_2=fun_v( y + (h/2.0) );
		k_2=fun_x( v + ( ( h * k_1 ) / 2.0) );

		zk_3=fun_v( y + (h/2.0) );
		k_3=fun_x( v + ( ( h * k_2 ) / 2.0) );

		zk_4=fun_v( y + h );		
		k_4=fun_x( v + ( h * k_3 ) );
		
		//actualizacion de los valores bajo el metodo de Runge-Kutta
		y=y+( h/6.0 * ( k_1+k_4+( 2 * k_2)+( 2 * k_3 )) );
		v=v+( h/6.0 * ( zk_1+zk_4+( 2 * zk_2)+( 2 * zk_3 )) );
		
		//impresion de los valores de posicion, velocidad y tiempo
		if(y>dist_max)
		{
			cout << y << " " << v << " " << t << endl;
		}
		//control de la velocidad maxima permitida.
		else
		{
			centinela=false;
		}
	}
	
}

