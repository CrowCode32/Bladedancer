// Fill out your copyright notice in the Description page of Project Settings.


#include "CutsceneManager.h"

void UCutsceneManager::PlayCutscene(ULevelSequence* Sequence)
{
	if (Sequence)
	{
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		if (PlayerController)
		{
			FMovieSceneSequencePlaybackSettings Settings;
			Settings.bHidePlayer = true;
			ALevelSequenceActor* SequenceActor;
			SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), Sequence, Settings, SequenceActor);

			if (SequencePlayer)
			{
				SequencePlayer->Play();
			}
		}
	}
}

void UCutsceneManager::PauseCutscene()
{
	if (SequencePlayer) { SequencePlayer->Pause(); }
}

void UCutsceneManager::ContinueCutscene()
{
	if (SequencePlayer) { SequencePlayer->Play(); }
}
