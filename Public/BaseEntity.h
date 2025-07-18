// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BaseEntity.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UBaseEntity : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MYGAME_API IBaseEntity
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual float CalculateTotalDamage(const float BaseDamage);
	virtual float CalculateTotalATK();
	virtual float CalculateTotalATK(float BaseATK);
	virtual void ReceiveKnockback(const float Force, const FVector Direction);
	virtual void TakeDamage(const float BaseDamage);
	virtual bool TakeDamage(const float BaseDamage, const float KnockbackForce, const FVector KnockbackDirection);
    virtual void Attack1(IBaseEntity* Entity);
    virtual void Attack2(IBaseEntity* Entity);
	virtual void SpawnAt(const FVector location);
};
