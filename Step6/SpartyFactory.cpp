/**
 * \file SpartyFactory.cpp
 *
 * \author Ethan Clifford
 */

#include "pch.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"

using namespace Gdiplus;
using namespace std;

/** This is a concrete factory method that creates our Sparty actor.
* \returns Pointer to an actor object
*/
std::shared_ptr<CActor> CSpartyFactory::Create()
{
    shared_ptr<CActor> actor = make_shared<CActor>(L"Sparty");

    auto torso = make_shared<CImageDrawable>(L"Torso", L"images/sparty_torso.png");
    torso->SetCenter(Point(44, 138));
    torso->SetPosition(Point(0, -114));
    actor->SetRoot(torso);

    auto lleg = make_shared<CImageDrawable>(L"Left Leg", L"images/sparty_lleg.png");
    lleg->SetCenter(Point(10, -20));
    lleg->SetPosition(Point(27, 0));
    torso->AddChild(lleg);

    auto rleg = make_shared<CImageDrawable>(L"Right Leg", L"images/sparty_rleg.png");
    rleg->SetCenter(Point(10, -20));
    rleg->SetPosition(Point(-27, 0));
    torso->AddChild(rleg);

    auto headb = make_shared<CImageDrawable>(L"Head Bottom", L"images/sparty_lhead.png");
    headb->SetCenter(Point(25, 20));
    headb->SetPosition(Point(0, -130));
    torso->AddChild(headb);

    auto headt = make_shared<CHeadTop>(L"Head Top", L"images/sparty_head.png");
    headt->SetCenter(Point(22, 127));
    headt->SetPosition(Point(0, -31));
    headb->AddChild(headt);

    headt->SetLeftEyeOffset(Point(18, 27));
    headt->SetRightEyeOffset(Point(-23, 27));
    headt->SetLeftEyebrowOffset(Point(11, 15));
    headt->SetRightEyebrowOffset(Point(-30, 15));

    auto larm = make_shared<CImageDrawable>(L"Left Arm", L"images/sparty_larm.png");
    larm->SetCenter(Point(-50, 130));
    larm->SetPosition(Point(10, -10));
    torso->AddChild(larm);

    auto rarm = make_shared<CImageDrawable>(L"Right Arm", L"images/sparty_rarm.png");
    rarm->SetCenter(Point(125, 130));
    rarm->SetPosition(Point(10, -10));
    torso->AddChild(rarm);


    actor->AddDrawable(larm);
    actor->AddDrawable(rarm);
    actor->AddDrawable(rleg);
    actor->AddDrawable(lleg);
    actor->AddDrawable(torso);
    actor->AddDrawable(headb);
    actor->AddDrawable(headt);

    return actor;
}
