#include <iostream>
using namespace std;
/*
【問題】

Objectクラス
x, y, z座標を保存する変数、Update関数を持つ。
Update関数はvirtualで作ってください。
*/
class Object
{
public:
	Object();
	~Object();
	virtual void Update();
protected:
	float x;
	float y;
	float z;
};

Object::Object()
{
	x = y = z = 0;
}

Object::~Object()
{
}

void Object::Update()
{
	cout << "x=" << x << ",y=" << y << ",z=" << z << "\n";
}

/*
Vehicle(乗り物)クラス
Objectクラスを継承したクラス。
ここではSpeedUpクラスを追加してください。
またspeedとaccelの変数をここで追加してください。
SpeedUpクラスはvirtualで作ってください。
(正確な速度の処理を行いたい場合は、向きと加速度で、
	ベクトルを計算する方法でも構いません。)*/

class Vehicle : public Object
{
public:
	Vehicle();
	~Vehicle();
	virtual void SpeedUp();
	virtual void SpeedDown();
	virtual void setAccel(float index);
	virtual void setBrake(float index);
 	virtual void Update();
protected:
	float Speed;
	float Accel;
	float brake;
};

Vehicle::Vehicle()
{
	Speed = Accel = brake = 0;
}

Vehicle::~Vehicle()
{
}

void Vehicle::SpeedUp()
{
	Speed += Accel;
}

void Vehicle::SpeedDown()
{
	Speed += brake;
}

void Vehicle::setAccel(float index)
{
	if (index < 0 || index>5)
	{
		cout << "Accel数値が大きすぎます,1～5の間で指定してください\n";
		return;
	}
	Accel = index;
}

void Vehicle::setBrake(float index)
{
	if (index < 0 || index>5)
	{
		cout << "brakeの数値が大きすぎます,1～5の間で指定してください\n";
		return;
	}
	else
	{
		brake = -brake;
	}

}

void Vehicle::Update()
{
	x += Speed;
	cout << "Spped=" << Speed << ",Accel=" << Accel<<endl;
	cout << "x=" << x << ",y=" << y << ",z=" << z << endl;
}

/*
Car(車)クラス
Vehicleクラスを継承したクラス
Speedの変更をここでCar用に実装してください。*/

class Car : public Vehicle
{
public:
	Car();
	~Car();
	virtual void SpeedUp();
	virtual void SpeedDown();
	void setAccel(float index);
	void setBrake(float index);
	virtual void Update();
private:

};

Car::Car()
{
}

Car::~Car()
{
}

void Car::SpeedUp()
{
	Speed = Speed + Accel * 1.2f;
}

void Car::SpeedDown()
{
	Speed = Speed + brake * 1.2f;
}

void Car::setAccel(float index)
{
	if (index < 0 || index>25)
	{
		cout << "Accel数値が大きすぎます,1～25の間で指定してください\n";
		return;
	}
	Accel = index;
}

void Car::setBrake(float index)
{
	if (index < 0 || index>15)
	{
		cout << "brakeの数値が大きすぎます,1～15の間で指定してください\n";
		return;
	}
	else
	{
		brake = -brake;
	}
}

void Car::Update()
{
	x += Speed;
	cout << "Spped=" << Speed << ",Accel=" << Accel << ",Brake=" << brake << endl;
	cout << "x=" << x << ",y=" << y << ",z=" << z << endl;
}

class PoliceCar : public Car
{
public:
	PoliceCar();
	~PoliceCar();
	void switchSilent();
	void SpeedUp();
	void SpeedDown();
	void Update();
private:
	bool silent;
	int s;
};

PoliceCar::PoliceCar()
{
	silent = false;
	s = 0;
}

PoliceCar::~PoliceCar()
{
}

void PoliceCar::switchSilent()
{
	cout << "現在サイレントは";
	if (silent==true)
	{
		cout << "On";
	}
	else if(silent == false)
	{
		cout << "Off";
	}
	cout << "になっています、変更しますか?" << endl;
	cout << "変更する場合は1,変更しない場合は0,と入力してください"<<endl;
	cin >> s;
	if (s==1)
	{
		silent = !silent;
	}
	else if(s==0)
	{
		return;
	}
}

void PoliceCar::SpeedUp()
{
	Speed = Speed + Accel * 1.5f;
}

void PoliceCar::SpeedDown()
{
	Speed = Speed + brake * 1.5f;
}

void PoliceCar::Update()
{
	x += Speed;
	cout << "Spped=" << Speed << ",Accel=" << Accel << ",Brake=" << brake << endl;
	cout << "x=" << x << ",y=" << y << ",z=" << z << endl;
	if (silent == true)
	{
		cout << "サイレントが鳴っています" << endl;
	}
	else if (silent == false)
	{
		cout << "サイレントはなっていません" << endl;
	}
}


/*

	流れを理解するという意味で、
	この親クラスから派生クラスを作っていってほしいので、
	中の計算処理やデータの設定の仕方は、
	適当に行ってもらって結構です。



	また、このクラスは必ず提出してください。
	成績に加味します。




	時間があれば、
	Vehicleクラスを継承して、
	bicycle(自転車)やbike(オートバイ)
	といったクラスの作成や、
	Carをさらに継承したpolice carや、truckなどの
	クラスを作成してみてください。
*/

int main()
{
	PoliceCar police;
	police.setAccel(12);
	police.setBrake(10);
	police.SpeedUp();
	for (int i = 0; i < 30; i++)
	{
		//SpeedはAccel*1.5なので　12*1.5がSpeedになる
		//Carの場合は1.2倍
		police.Update();
	}
	police.switchSilent();
	for (int i = 0; i < 10; i++)
	{
		police.Update();
	}
	
	Car car;
	car.setAccel(10);
	car.setBrake(5);
	car.SpeedUp();
	//CarのSpeedUpは*1,2
	//SpeedはAccel*1.2なので　Speedが12になる
	car.Update();
	
}