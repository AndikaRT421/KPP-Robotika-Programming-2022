// NAMA		: Andika Rahman Teja
// NRP		: 5025221022
// Jurusan	: Teknik Informatika

#include <iostream>
#include <cmath>


#define _USE_MATH_DEFINES // untuk mengeluarkan nilai pi
#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan

int mencari_V0(int variabel1, int variabel2)
{
	/* Tulis fungsi mencari v0 kalian disini */
	int hasil;
	hasil = variabel1 - variabel2; // adanya losses
	return hasil;
	
}

float mencari_jarak (int var)
{
	float jarak;
	float sudut_radian;
	sudut_radian = (SUDUT*M_PI)/180; // mengubah derajat ke radian
	jarak = (var*var*sin(2*sudut_radian)) / GRAVITASI; // sesuai rumus pada Fisika 1
    // jarak = lround (jarak); // ternyata bukan pembulatan dengan round
	jarak = trunc (jarak); // menggunakan pembulatan ke bawah dengan trunc
	return jarak;
}

float speed_dgn_loss(int sesuatu)
{
	/* tulis fungsi hitung_loss kalian disini */
	float speed;
	float sudut_radian2;
	sudut_radian2 = (SUDUT*M_PI)/180; // mengubah derajat ke radian
	speed = sqrt((sesuatu * GRAVITASI)/sin (2*sudut_radian2));
	return speed;
}


int main() {
    /* tulis kode utama kalian disini */
  	int masukan, losses;
	std:: cin >> masukan;

	if (masukan >= 1 && masukan <= 10)
	{
		losses = 1;
	}
	else if (masukan >= 11 && masukan <= 20)
	{
		losses = 3;
	}
	else if (masukan >= 21 && masukan <= 30)
	{
		losses = 5;
	}
	else
	{
		return 0;
	}
	int V0;
	V0 = mencari_V0 (masukan, losses);

	int jarak;
	jarak = mencari_jarak(V0);

	float kecepatan_tangensial;
	kecepatan_tangensial = speed_dgn_loss(jarak) + losses;

	if (kecepatan_tangensial <= 30)
	{
		std:: cout << jarak << " " << kecepatan_tangensial << std::endl;
	}
	


  	/* std::cout << jarak << " " << kecepatan tangensial << std::endl */
    return 0;
}