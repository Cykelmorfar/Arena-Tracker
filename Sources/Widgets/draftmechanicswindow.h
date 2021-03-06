#ifndef DRAFTMECHANICSWINDOW_H
#define DRAFTMECHANICSWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "scorebutton.h"
#include "../Synergies/draftitemcounter.h"


class DraftMechanicsWindow : public QMainWindow
{
    Q_OBJECT

//Constructor
public:
    DraftMechanicsWindow(QWidget *parent, QRect rect, QSize sizeCard, int screenIndex, bool patreonVersion, DraftMethod draftMethod, bool normalizedLF);
    ~DraftMechanicsWindow();


//Variables
private:
    bool patreonVersion;
    ScoreButton *scoresPushButton;
    ScoreButton *scoresPushButton2;
    DraftItemCounter **cardTypeCounters, **mechanicCounters;
    DraftItemCounter *manaCounter;
    int scoreWidth;
    bool showingHelp;
    DraftMethod draftMethod;

//Metodos
private:
    void deleteDraftItemCounters();

public:
    void setDraftMethod(DraftMethod draftMethod);
    void setScores(int deckScoreHA, int deckScoreLF);
    void updateManaCounter(int numIncrease, int draftedCardsCount);
    void clearLists();
    void updateCounters(QStringList &spellList, QStringList &minionList, QStringList &weaponList, QStringList &aoeList, QStringList &tauntList, QStringList &survivabilityList, QStringList &drawList, QStringList &pingList, QStringList &damageList, QStringList &destroyList, QStringList &reachList);
    void setTheme();
    void setNormalizedLF(bool value);

public slots:
    void sendItemEnter(QList<DeckCard> &deckCardList, QRect &labelRect);

signals:
    void itemEnter(QList<DeckCard> &deckCardList, QPoint &originList, int maxLeft, int maxRight);
    void itemLeave();
    void showPremiumDialog();
};

#endif // DRAFTMECHANICSWINDOW_H
