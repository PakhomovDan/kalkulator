#pragma once
#include <Math.h>
#include <iostream>
#include"string";
#include <SDL.h>
#include <Windows.h>
#include <complex>
using namespace std;


void ViborOperacii(int a);
void Menu();
void IntegralPokazatelnaya();
void IntegralPolinoma();
void IntegralStepennaya();
void IntegralLogarifmicheskaya();
void IntegralSinusoida();
void IntegralKosinusoida();


void GrafPolinom();
void GrafPokazatelnaya();
void GrafStepennoi();
void GrafLogarifmicheskoi();
void GrafSinusoida();
void GrafKosinusoida();

void PoiskKornyaPolindroma();
void PoiskKornyaStepennoi();
void PoiskKornyaPokazatelnoi();
void PoiskKornyaLogarifmicheskoi();
void PoiskKornyaSinusoida();
void PoiskKornyaKosinusoida();

void ExtremumPolinom();
void ExtremumStepenoi();
void ExtremumPokazatelnoi();
void ExtremumLogarifmicheskoi();
void ExtermumSinusoida();
void ExtremumKosinusoida();

complex<double>* KompleksKoren(double mass[], int n);
complex<double> Kompleks(int n, double mass[], complex<double> x);
double Znachenie(int n, double mass[], double x);
