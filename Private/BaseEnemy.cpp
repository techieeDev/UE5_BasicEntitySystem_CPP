#include "BaseEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Game/AMainCharacter.h"

// Sets default values
ABaseEnemy::ABaseEnemy()
{
 	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Level = 1;
	HP = 450;
	ATK = 850;
	DEF = 1000;
	KnockbackForce = 100;
}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
}

int ABaseEnemy::GetLevel() {return Level;}

float ABaseEnemy::GetOnDeathPlayerEXPMultiplier() {
	switch (Rank)
	{
		case ERank::Alpha : return 2000;
		case ERank::Crystal: return 3200;
		case ERank::Eclipse: return 7000;
		default: return 2000;
	}
}

float ABaseEnemy::CalculateTotalATK() {
	return ATK;
}

float ABaseEnemy::CalculateTotalDamage(float BaseDamage) {
	return (BaseDamage / (DEF * 2));
}

void ABaseEnemy::ReceiveKnockback(float Force, FVector Direction) {
	float TotalForce = (Force*KnockbackBasicMultiplier) / (DEF * 2);
	GetCharacterMovement()->AddImpulse(TotalForce * Direction, true);
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Purple, TEXT("Knockback Received"));
}

bool ABaseEnemy::TakeDamage(float BaseDamage, float _KnockbackForce, FVector KnockbackDirection)
{
	ReceiveKnockback(_KnockbackForce, KnockbackDirection);

	float TotalDamage = CalculateTotalDamage(BaseDamage);
	HP -= TotalDamage;

	/* Debug */
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Enemy's HP:") + FString::SanitizeFloat(HP));
	/*-------*/

	// Eliminate entity if health <= 0
	if (HP <= 0)
		return this->Destroy();
	else
		return false;
}

void ABaseEnemy::Attack1(IBaseEntity* Entity)
{
	if (Entity != nullptr)
		if (Entity->_getUObject()->IsA(AMainCharacter::StaticClass())){
			float BaseDamage = CalculateTotalATK();
			Entity->TakeDamage(BaseDamage);
		}
}

void ABaseEnemy::Attack1(TScriptInterface<IBaseEntity> Entity)
{
	if (Entity.GetInterface())
	{
		Attack1(Cast<IBaseEntity>(Entity.GetObject()));
	}
}

void ABaseEnemy::SpawnAt(FVector location) {
	SetActorLocation(location);
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//DrawDebugCapsule(GetWorld(), GetActorLocation(), 100.0f, 49.0F, FQuat::Identity, FColor::Red, false, 0.5f, 1, 3.5f);
}

