/**
 * 残日数を取得する。
 * @returns {RemainingDay}: 残日数
 */
    function CalcRemainingDays() {
        var nowDate = new NowDate();
        var targetDate = new TargetDate(2018, 10, 21);
        var diffDate = getDateDiff(nowDate.date, targetDate.date);
        var msg ='<p>残り'+diffDate+'日</p>'; 
        $('#day').html(msg)
    }

function hoge() {
    alert();
}

/**
 * 対象日を指定する。
 * @param {any} _year: 対象の年
 * @param {any} _month: 対象の月
 * @param {any} _day: 対象の日
 */
var TargetDate = function (_year, _month, _day) {
    this.date = new Date(_year, _month - 1, _day, 0, 0)
}

/**
 * 現在日時を取得する。
 */
var NowDate = function () {
    this.date = new Date();
}

/**
 * @param dateStartStr
 * @param dateEndtStr
 */
var getDateDiff = function (dateStartStr, dateEndStr) {

    var dateStart = new Date(dateStartStr);
    var dateEnd = new Date(dateEndStr);

    //ミリ秒に変換
    var msDiff = dateEnd.getTime() - dateStart.getTime();

    // 経過ミリ秒÷(1000ミリ秒×60秒×60分×24時間) 端数切捨て
    var daysDiff = Math.floor(msDiff / (1000 * 60 * 60 * 24));

    // 計算した差分に1加算してreturn
    return ++daysDiff;
};