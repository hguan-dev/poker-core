#include "PokerGame.hpp"
#include "BettingRound.hpp"
#include "HandEvaluator.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

/*
========================================
TODO GUIDE (for the learner)
========================================
Implement the following methods so the game runs end-to-end:

1) collectBlinds()
   - Goal: Post small/big blinds based on who is the dealer.
   - If playerIsDealer:
       player posts small blind, bot posts big blind.
     Else:
       bot posts small blind, player posts big blind.
   - Deduct chips from each participant, set each participant's currentBet accordingly.
   - Increase the pot by (smallBlind + bigBlind).
   - Set currentBet = bigBlind (this is the bet others must call to stay in the hand).

2) dealHoleCards()
   - Goal: Deal 2 cards to each player from the deck.
   - Use deck->popTop() twice for player and twice for bot.
   - Save into player->setHand({ ... }) and bot->setHand({ ... }).

3) dealCommunityCards(int numCards)
   - Goal: Deal `numCards` board cards onto communityCards[] in order.
   - Use communityCardIndex to place them sequentially.
   - For each i in [0, numCards):
       communityCards[communityCardIndex++] = deck->popTop();

4) handlePhase(int numCommunityCards)
   - Goal: Run one betting phase (e.g., preflop/flop/turn/river).
   - If numCommunityCards > 0, deal that many community cards first.
   - Then call executeBettingRound(*this) to run the betting for that street.
   - Make sure executeBettingRound can access/get/set pot/currentBet via the methods
     provided on PokerGame/Player/Bot.

5) preflop(), flop(), turn(), river()
   - Goal: Simply call handlePhase with the correct number of community cards.
   - preflop: 0 (nothing dealt here; hole cards already dealt)
   - flop:    3
   - turn:    1
   - river:   1

6) payout()
   - Goal: Award the pot to the winner or split on a tie.
   - Use HandEvaluator to evaluate both hands with communityCards.
   - If equal strength: split pot (each gets pot/2).
   - Else winner gets the whole pot.
   - Reset pot to 0 at the end.

7) resetGameState()
   - This is already implemented, but understand it:
     - Reset pot/currentBet/board index.
     - Shuffle deck, reset player & bot state (e.g., active flags, current bets, etc.).

8) shiftDealerButton()
   - Toggles dealer each hand (already implemented).
========================================
*/

PokerGame::PokerGame() : pot(0), currentBet(0), playerIsDealer(true)
{
    deck = std::make_unique<Deck>();
    player = std::make_unique<Player>(100.0);
    bot = std::make_unique<Bot>(100.0);
}

void PokerGame::playGame()
{
    while (true) {
        resetGameState();

        std::string play_again;
        std::cin >> play_again;

        if (play_again == "n") { return; }

        collectBlinds();// TODO: implement
        dealHoleCards();// TODO: implement

        preflop();// TODO: implement (calls handlePhase(0))
        flop();// TODO: implement (calls handlePhase(3))
        turn();// TODO: implement (calls handlePhase(1))
        river();// TODO: implement (calls handlePhase(1))

        if (player->isActive() && bot->isActive()) {
            payout();// TODO: implement
        } else if (!player->isActive()) {
            bot->addChips(pot);
        } else if (!bot->isActive()) {
            player->addChips(pot);
        } else {
            throw std::runtime_error("Invalid folding logic.");
        }

        if (player->getChips() == 0 || bot->getChips() == 0) { break; }

        shiftDealerButton();
    }
}

void PokerGame::resetGameState()
{
    pot = 0;
    currentBet = 0;
    communityCards.fill(Card());
    communityCardIndex = 0;
    deck->shuffle();
    player->reset();
    bot->reset();
}

void PokerGame::collectBlinds()
{
    // TODO:
    // - Use smallBlind = 0.5, bigBlind = 1.0.
    // - Based on playerIsDealer, have dealer post small blind, other post big blind.
    // - Deduct chips from each, set their current bets, add to pot, set currentBet = bigBlind.
    // HINT: player->deductChips(...); player->setCurrentBet(...); etc.
    throw std::logic_error("collectBlinds: TODO");
}

void PokerGame::shiftDealerButton()
{
    playerIsDealer = !playerIsDealer;
}

void PokerGame::dealHoleCards()
{
    // TODO:
    // - Give each player two cards from deck->popTop().
    // - Look at the Player and Bot class to see how to add cards
    throw std::logic_error("dealHoleCards: TODO");
}

void PokerGame::dealCommunityCards(int numCards)
{
    // TODO:
    // - For i in [0, numCards): communityCards[communityCardIndex++] = deck->popTop();
    // - No burning here unless you want to add that rule explicitly.
    throw std::logic_error("dealCommunityCards: TODO");
}

double PokerGame::getCurrentBet()
{
    return currentBet;
}

void PokerGame::setCurrentBet(double newBet)
{
    currentBet = newBet;
}

double PokerGame::getPot()
{
    return pot;
}

void PokerGame::addToPot(double value)
{
    pot += value;
}

void PokerGame::handlePhase(int numCommunityCards)
{
    // TODO:
    // - If numCommunityCards > 0, call dealCommunityCards(numCommunityCards).
    // - Then run betting: executeBettingRound(*this);
    // - The betting round should manage calls/raises/folds and update pot/current bets via PokerGame API.
    throw std::logic_error("handlePhase: TODO");
}

void PokerGame::preflop()
{
    throw std::logic_error("preflop: TODO");
}

void PokerGame::flop()
{
    throw std::logic_error("flop: TODO");
}

void PokerGame::turn()
{
    throw std::logic_error("turn: TODO");
}

void PokerGame::river()
{
    throw std::logic_error("river: TODO");
}

void PokerGame::payout()
{
    // TODO:
    // - Use HandEvaluator to evaluate both hands given communityCards.
    // - If tie: split pot (each gets pot/2). Else, winner gets full pot.
    // - Reset pot to 0 after paying out.
    //
    throw std::logic_error("payout: TODO");
}

