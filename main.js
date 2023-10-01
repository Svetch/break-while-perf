const end = 1000000;
const f = 1000;

function testWhile() {
    function test_while() {
        let t = true;
        let i = 0
        while (t) {
            i++;
            if (i >= end) {
                t = false;
            }
        }
    }

    console.time("while");
    for (let x = 0; x < f; x++) {
        test_while();
    }
    console.timeEnd("while");
}

function testDoWhile() {
    function test_do_while() {
        let t = true;
        let i = 0
        do {
            if (i >= end) {
                t = false;
            }
            i++;
        } while (t)
    }

    console.time("dowhile");
    for (let x = 0; x < f; x++) {
        test_do_while();
    }
    console.timeEnd("dowhile");
}

function testBreak() {

    function test_break() {
        let i = 0
        while (true) {
            i++;
            if (i >= end) break;
        }
    }

    console.time("break");
    for (let x = 0; x < f; x++) {
        test_break();
    }
    console.timeEnd("break");
}

testBreak();
testWhile();
testDoWhile();
