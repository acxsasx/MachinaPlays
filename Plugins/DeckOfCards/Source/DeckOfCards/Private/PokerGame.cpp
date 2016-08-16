// Robert Chubb - Saxon Rah - Parabolic Labs
#include "DeckOfCardsPrivatePCH.h"
#include "PokerGame.h"
 
bool APokerGame::DrawPokerHand(FStandardCardArray &OutHand)
{
	return Poker->DrawCardsFromTop(5, OutHand);
}

EStandardPokerHandRank APokerGame::AnalyzePokerHand(FStandardCardArray InHand)
{
	PokerHandAnalyzer pha;
	return pha.AnalyzeHand(InHand);
}

void APokerGame::TestAll()
{
	FOutputDeviceNull ar;
	FString DrawnHandTypeFString = "";
	FStandardCardArray HandArray;

	UE_LOG(GenLog, Warning, TEXT("Test All--------------------------"));
	Poker->PrintDeckToLog();
	Poker->CallFunctionByNameWithArguments(TEXT("DisplayDeck"), ar, NULL, true);


	//////////////////////////////////////////////////////////////////////////
	// Random Hand
	UE_LOG(GenLog, Warning, TEXT("Random Hand--------------------------"));
	DrawPokerHand(HandArray);
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);

	UE_LOG(GenLog, Warning, TEXT("Random Hand--------------------------"));
	DrawPokerHand(HandArray);
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);

	UE_LOG(GenLog, Warning, TEXT("Random Hand--------------------------"));
	DrawPokerHand(HandArray);
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);

	UE_LOG(GenLog, Warning, TEXT("Random Hand--------------------------"));
	DrawPokerHand(HandArray);
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);

	UE_LOG(GenLog, Warning, TEXT("Random Hand--------------------------"));
	DrawPokerHand(HandArray);
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// Royal Flush
	UE_LOG(GenLog, Warning, TEXT("Royal Flush--------------------------"));
	HandArray.DiscardAll();
	HandArray.ReserveCardArray(5);
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Ace));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_King));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Queen));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Jack));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Ten));
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);
	HandArray.DiscardAll();
	HandArray.ReserveCardArray(5);
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Hearts, EStandardCardRank::CR_Ace));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_King));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Queen));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Jack));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Ten));
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);
	//////////////////////////////////////////////////////////////////////////
	// Straight Flush
	UE_LOG(GenLog, Warning, TEXT("Straight Flush--------------------------"));
	HandArray.DiscardAll();
	HandArray.ReserveCardArray(5);
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Clubs, EStandardCardRank::CR_Jack));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Clubs, EStandardCardRank::CR_Ten));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Clubs, EStandardCardRank::CR_Nine));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Clubs, EStandardCardRank::CR_Eight));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Clubs, EStandardCardRank::CR_Seven));
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);


	//////////////////////////////////////////////////////////////////////////
	// Four of a Kind
	HandArray.DiscardAll();
	HandArray.ReserveCardArray(5);
	UE_LOG(GenLog, Warning, TEXT("Four of a Kind--------------------------"));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Clubs, EStandardCardRank::CR_Five));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Diamonds, EStandardCardRank::CR_Five));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Hearts, EStandardCardRank::CR_Five));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Five));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Diamonds, EStandardCardRank::CR_Two));
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);


	//////////////////////////////////////////////////////////////////////////
	// Full House
	UE_LOG(GenLog, Warning, TEXT("Full House--------------------------"));
	HandArray.DiscardAll();
	HandArray.ReserveCardArray(5);
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Six));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Hearts, EStandardCardRank::CR_Six));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Diamonds, EStandardCardRank::CR_Six));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Clubs, EStandardCardRank::CR_King));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Hearts, EStandardCardRank::CR_King));
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);


	//////////////////////////////////////////////////////////////////////////
	// Flush
	UE_LOG(GenLog, Warning, TEXT("Flush--------------------------"));
	HandArray.DiscardAll();
	HandArray.ReserveCardArray(5);
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Diamonds, EStandardCardRank::CR_Jack));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Diamonds, EStandardCardRank::CR_Nine));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Diamonds, EStandardCardRank::CR_Eight));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Diamonds, EStandardCardRank::CR_Four));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Diamonds, EStandardCardRank::CR_Two));
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);


	//////////////////////////////////////////////////////////////////////////
	// Straight
	UE_LOG(GenLog, Warning, TEXT("Straight--------------------------"));
	HandArray.DiscardAll();
	HandArray.ReserveCardArray(5);
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Diamonds, EStandardCardRank::CR_Ten));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Clubs, EStandardCardRank::CR_Nine));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Hearts, EStandardCardRank::CR_Eight));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Diamonds, EStandardCardRank::CR_Seven));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Clubs, EStandardCardRank::CR_Six));
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);


	//////////////////////////////////////////////////////////////////////////
	// Three of a Kind
	UE_LOG(GenLog, Warning, TEXT("Three of a Kind--------------------------"));
	HandArray.DiscardAll();
	HandArray.ReserveCardArray(5);
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Clubs, EStandardCardRank::CR_Queen));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Queen));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Hearts, EStandardCardRank::CR_Queen));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Hearts, EStandardCardRank::CR_Nine));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Clubs, EStandardCardRank::CR_Two));
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);


	//////////////////////////////////////////////////////////////////////////
	// Two Pair
	UE_LOG(GenLog, Warning, TEXT("Two Pair--------------------------"));
	HandArray.DiscardAll();
	HandArray.ReserveCardArray(5);
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Hearts, EStandardCardRank::CR_Jack));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Jack));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Clubs, EStandardCardRank::CR_Three));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Three));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Hearts, EStandardCardRank::CR_Two));
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);
	

	//////////////////////////////////////////////////////////////////////////
	// One Pair
	UE_LOG(GenLog, Warning, TEXT("One Pair--------------------------"));
	HandArray.DiscardAll();
	HandArray.ReserveCardArray(5);
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Ten));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Hearts, EStandardCardRank::CR_Ten));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Eight));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Hearts, EStandardCardRank::CR_Two));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Clubs, EStandardCardRank::CR_Four));
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);


	//////////////////////////////////////////////////////////////////////////
	// High Card
	UE_LOG(GenLog, Warning, TEXT("High Card--------------------------"));
	HandArray.DiscardAll();
	HandArray.ReserveCardArray(5);
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Diamonds, EStandardCardRank::CR_King));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Diamonds, EStandardCardRank::CR_Queen));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Seven));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Spades, EStandardCardRank::CR_Four));
	HandArray.AddCard(FStandardCard(EStandardCardSuit::CS_Hearts, EStandardCardRank::CR_Three));
	DrawnHandTypeFString = ConvertEnumValueToString<EStandardPokerHandRank>("EStandardPokerHandRank", AnalyzePokerHand(HandArray));
	UE_LOG(GenLog, Warning, TEXT("Type of Hand : %s"), *DrawnHandTypeFString);
}

