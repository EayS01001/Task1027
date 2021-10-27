#include <iostream>
using namespace std;
/*
�y���z

Object�N���X
x, y, z���W��ۑ�����ϐ��AUpdate�֐������B
Update�֐���virtual�ō���Ă��������B
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
Vehicle(��蕨)�N���X
Object�N���X���p�������N���X�B
�����ł�SpeedUp�N���X��ǉ����Ă��������B
�܂�speed��accel�̕ϐ��������Œǉ����Ă��������B
SpeedUp�N���X��virtual�ō���Ă��������B
(���m�ȑ��x�̏������s�������ꍇ�́A�����Ɖ����x�ŁA
	�x�N�g�����v�Z������@�ł��\���܂���B)*/

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
		cout << "Accel���l���傫�����܂�,1�`5�̊ԂŎw�肵�Ă�������\n";
		return;
	}
	Accel = index;
}

void Vehicle::setBrake(float index)
{
	if (index < 0 || index>5)
	{
		cout << "brake�̐��l���傫�����܂�,1�`5�̊ԂŎw�肵�Ă�������\n";
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
Car(��)�N���X
Vehicle�N���X���p�������N���X
Speed�̕ύX��������Car�p�Ɏ������Ă��������B*/

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
		cout << "Accel���l���傫�����܂�,1�`25�̊ԂŎw�肵�Ă�������\n";
		return;
	}
	Accel = index;
}

void Car::setBrake(float index)
{
	if (index < 0 || index>15)
	{
		cout << "brake�̐��l���傫�����܂�,1�`15�̊ԂŎw�肵�Ă�������\n";
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
	cout << "���݃T�C�����g��";
	if (silent==true)
	{
		cout << "On";
	}
	else if(silent == false)
	{
		cout << "Off";
	}
	cout << "�ɂȂ��Ă��܂��A�ύX���܂���?" << endl;
	cout << "�ύX����ꍇ��1,�ύX���Ȃ��ꍇ��0,�Ɠ��͂��Ă�������"<<endl;
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
		cout << "�T�C�����g�����Ă��܂�" << endl;
	}
	else if (silent == false)
	{
		cout << "�T�C�����g�͂Ȃ��Ă��܂���" << endl;
	}
}


/*

	����𗝉�����Ƃ����Ӗ��ŁA
	���̐e�N���X����h���N���X������Ă����Ăق����̂ŁA
	���̌v�Z������f�[�^�̐ݒ�̎d���́A
	�K���ɍs���Ă�����Č��\�ł��B



	�܂��A���̃N���X�͕K����o���Ă��������B
	���тɉ������܂��B




	���Ԃ�����΁A
	Vehicle�N���X���p�����āA
	bicycle(���]��)��bike(�I�[�g�o�C)
	�Ƃ������N���X�̍쐬��A
	Car������Ɍp������police car��Atruck�Ȃǂ�
	�N���X���쐬���Ă݂Ă��������B
*/

int main()
{
	PoliceCar police;
	police.setAccel(12);
	police.setBrake(10);
	police.SpeedUp();
	for (int i = 0; i < 30; i++)
	{
		//Speed��Accel*1.5�Ȃ̂Ł@12*1.5��Speed�ɂȂ�
		//Car�̏ꍇ��1.2�{
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
	//Car��SpeedUp��*1,2
	//Speed��Accel*1.2�Ȃ̂Ł@Speed��12�ɂȂ�
	car.Update();
	
}