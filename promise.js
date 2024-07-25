/*
PROMISE IS AN OBJECT REPRESENTING THE EVENTUAL
COMPLETION OR FAILURE OF AN ASYNCHRONOUS OPERATION.
*/
const getDogPromise = () => {
  return new Promise((resolve, reject) => {
    const grade = Math.floor(Math.random() * 101);
    if (grade >= 85) {
      resolve();
    } else {
      reject();
    }
  });
};
getDogPromise()
  .then(() => {
    console.log("Hurry!! You will get a dog");
  })
  .catch(() => {
    console.log("You should do more effort to get a dog");
  });
//TODO: 2ND EXAMPLE
const fakeRequest = (url) => {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      const pages = {
        "user/": [
          { id: 1, name: "Mohsin" },
          { id: 2, name: "Jawad" },
        ],
        "user/1": {
          firstName: "Muhammad",
          lastName: "Mohsin",
          father: "Yasam Taj",
          age: 22,
          topPost: 234,
        },
        "user/2": {
          firstName: "Muhammad",
          lastName: "Jawad",
          father: "Yasam Taj",
          age: 20,
          topPost: 235,
        },
        "post/234": {
          text: "Hello you beautiful people",
        },
        "post/235": {
          message: "You are awesome",
        },
      };
      const data = pages[url];
      if (data) {
        resolve({ respond: 200, data });
      } else {
        reject({ respond: 404, data: "Data not found" });
      }
    }, 2000);
  });
};
fakeRequest("user/")
  .then((res) => {
    // console.log(res);
    return fakeRequest(`user/${res.data[0].id}`);
  })
  .then((res) => {
    return fakeRequest(`post/${res.data.topPost}`);
  })
  .then((res) => {
    console.log(res.data);
  })
  .catch((err) => {
    console.log(err);
  });
