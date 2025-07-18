// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEntity.h"

// Add default functionality here for any IBaseEntity functions that are not pure virtual.

float IBaseEntity::CalculateTotalDamage(float BaseDamage) {
	return 0;
}

float IBaseEntity::CalculateTotalATK() {
	return 0;
}

float IBaseEntity::CalculateTotalATK(float BaseATK) {
	return 0;
}

void IBaseEntity::ReceiveKnockback(float Force, FVector Direction) {

}

void IBaseEntity::TakeDamage(float BaseDamage) {

}

bool IBaseEntity::TakeDamage(float BaseDamage, float KnockbackForce, FVector KnockbackDirection) {
	return false;
}

void IBaseEntity::Attack1(IBaseEntity* Entity) {

}

void IBaseEntity::Attack2(IBaseEntity* Entity) {

}


void IBaseEntity::SpawnAt(FVector location) {
}