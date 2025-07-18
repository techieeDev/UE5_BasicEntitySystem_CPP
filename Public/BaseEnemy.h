// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseEntity.h"
#include "BaseEnemy.generated.h"

UENUM(BlueprintType)
enum class ERank : uint8 { Alpha, Crystal, Eclipse };

UCLASS(Blueprintable)
class MYGAME_API ABaseEnemy : public ACharacter, public IBaseEntity
{
	GENERATED_BODY()

protected:

	// Enemy:Stats
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<ERank> Rank;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	int Level;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float HP;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float ATK;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float DEF;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float KnockbackForce;

	// Enemy:AI
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	float PlayerDetectionRange;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	float MinAttackRange;

	const float KnockbackBasicMultiplier = 5250;

public:	
	// Sets default values for this actor's properties
	ABaseEnemy();

	int GetLevel();

	float GetOnDeathPlayerEXPMultiplier();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual float CalculateTotalDamage(const float BaseDamage) override;

	virtual float CalculateTotalATK() override;

	virtual void ReceiveKnockback(const float Force, const FVector Direction) override;

	virtual bool TakeDamage(const float BaseDamage, const float _KnockbackForce, const FVector KnockbackDirection) override;

	virtual void Attack1(IBaseEntity* Entity) override;

	/* Blueprint callable 'Attack1()' function; Calls: Attack1(IBaseEntity* Entity) */
	UFUNCTION(BlueprintCallable, Category = "Combat")
	virtual void Attack1(TScriptInterface<IBaseEntity> Entity);

	virtual void SpawnAt(const FVector location) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
