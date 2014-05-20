#include "game_status_bar_widget.h"
#include "ui_game_statusbar_widget.h"

GameStatusBarWidget::GameStatusBarWidget(QWidget *parent)
    : QWidget(parent)
{
    _ui = new Ui::GameStatusBarWidget();
    _ui->setupUi(this);
}

GameStatusBarWidget::~GameStatusBarWidget()
{
    delete _ui;
}

void GameStatusBarWidget::initStatus(uint64 character_guid)
{
    Protocol::CSCharacterInitialDataReq characterInitialDataReq;
    GameNetwork::getInstance().sendMessage(Opcodes::CSCharacterInitialDataReq, characterInitialDataReq);
}

void GameStatusBarWidget::onPropertiesRsp(const Protocol::SCCharacterInitialDataRsp& characterInitialDataRsp)
{
    if (characterInitialDataRsp.char_initial_data.max_hp != 0)
    {
        float percent = (
            static_cast<float>(characterInitialDataRsp.char_initial_data.hp) / 
            static_cast<float>(characterInitialDataRsp.char_initial_data.max_hp)) * 100;

        _ui->progressHp->setValue(static_cast<int>(percent));
        _ui->progressHp->setFormat(
            QString::number(characterInitialDataRsp.char_initial_data.hp) + "/"
            + QString::number(characterInitialDataRsp.char_initial_data.max_hp));
    }

    if (characterInitialDataRsp.char_initial_data.next_exp != 0)
    {
        float percent = (static_cast<float>(characterInitialDataRsp.char_initial_data.exp) / 
            static_cast<float>(characterInitialDataRsp.char_initial_data.next_exp)) * 100;

        _ui->progressExp->setValue(static_cast<int>(percent));
        _ui->progressExp->setFormat(QString::number(percent) + "%");
    }

    _ui->lcdPower->display(static_cast<int>(characterInitialDataRsp.char_initial_data.power));
}

void GameStatusBarWidget::updateLevel(uint16 level)
{

}

void GameStatusBarWidget::updateCareer(uint8 career)
{

}

void GameStatusBarWidget::updateHP(uint32 hp, uint32 maxHp)
{

}

void GameStatusBarWidget::updateExp(uint32 exp)
{

}
