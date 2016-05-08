#include "tierratingbutton.h"
#include "ui_tierratingbutton.h"

TierRatingButton::TierRatingButton(const QString &tier, int rating)
    : ui(new Ui::TierRatingButton)
{
    ui->setupUi(this);

    setTier(tier);
    setRating(rating);
}

TierRatingButton::~TierRatingButton()
{
    delete ui;
}

void TierRatingButton::setRating(int rating)
{
    if (rating == -32769) {
        ui->rating->setText(tr("???"));
    } else {
        ui->rating->setNum(rating);
    }
}

void TierRatingButton::setTier(const QString &tier)
{
    ui->tier->setText(tier);
}
