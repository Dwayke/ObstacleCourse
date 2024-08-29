// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//FPlatformProcess::Sleep(3.0f);
    // Get the player pawn for player index 0 (usually the main player)
    APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0);

    if (Pawn)
    {
        // Get the location of the player pawn
        PawnLocation = Pawn->GetActorLocation();
    }	
	SetActorLocation(PawnLocation+ActorOffset);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    ActorOffset.X++;
    SetActorLocation(PawnLocation + ActorOffset);
}

