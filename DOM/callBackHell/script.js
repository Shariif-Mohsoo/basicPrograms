const btn = document.getElementById("btn");

const moveX = (ele, amount, delay, onSuccess, onFailure) => {
  setTimeout(() => {
    const eleLeft = ele.getBoundingClientRect().left;
    const eleRight = ele.getBoundingClientRect().right;
    const containerWidth = document.body.clientWidth;
    // console.log(eleLeft, eleRight, containerWidth);
    if (eleRight + amount >= containerWidth) {
      onFailure();
    } else {
      ele.style.transform = `translateX(${amount + eleLeft}px)`;
      onSuccess();
    }
  }, delay);
};
moveX(
  btn,
  200,
  1000,
  () => {
    //FIXME: success
    moveX(
      btn,
      200,
      1000,
      () => {
        //FIXME: SUCCESS
        moveX(
          btn,
          200,
          1000,
          () => {
            //FIXME: SUCCESS
            moveX(
              btn,
              200,
              1000,
              () => {
                //FIXME: SUCCESS
                moveX(
                  btn,
                  200,
                  1000,
                  () => {
                    //FIXME: SUCCESS
                    moveX(btn, 100, 200);
                  },
                  () => {
                    //TODO: FAILURE
                    alert("Can't move further");
                    btn.style.transform = "translateX(0)px";
                  }
                );
              },
              () => {
                //TODO: FAILURE
                alert("You can't move further");
              }
            );
          },
          () => {
            //TODO: FAILURE
            alert("You can't more further");
          }
        );
      },
      () => {
        //TODO: FAILURE
        alert("Can't more further");
      }
    );
  },
  () => {
    alert("Dear you can't move further");
    //TODO: failure
  }
);
