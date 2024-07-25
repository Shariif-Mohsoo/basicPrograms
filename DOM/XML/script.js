//TODO: ANOLDER METHOD
// const request = new XMLHttpRequest();
// request.addEventListener("load", function () {
//   //   console.log(request.responseText);
//   let data = JSON.parse(this.responseText);
//   const h1 = document.createElement("h1");
//   h1.innerText = data.name;
//   console.log(data);
//   const urls = data.films;
//   h1.innerText += " " + urls;
//   document.body.appendChild(h1);
// });
// request.addEventListener("error", function () {});
// request.open("GET", "https://swapi.dev/api/planets/1/");
// request.send();

//FIXME: NEW METHOD
// const fetchURL = (url = "https://swapi.dev/api/planets/1/") => {
//   return fetch(url);
// };
// const parseJson = (res) => {
//   if (!res.ok) throw new Error();
//   return res.json();
// };
// const getNext = (res) => {
//   const idx = Math.floor(Math.random() * res.films.length);
//   const url = res.films[idx];
//   return Promise.resolve(url);
// };
// const displayScreen = (res) => {
//   const h1 = document.createElement("h1");
//   h1.innerText = res.title;
//   document.body.appendChild(h1);
//   console.log(res);
//   return Promise.resolve(res.planets[0]);
// };
// fetchURL()
//   .then(parseJson)
//   .then(getNext)
//   .then(fetchURL)
//   .then(parseJson)
//   .then(displayScreen)
//   .then(fetchURL)
//   .then(parseJson)
//   .then(displayScreen)
//   .catch(() => {
//     console.log("The new error occur");
//   });

//FIXME: ANOTHER NEW VERSION AXIOS
// const fetchURL = (url = "https://swapi.dev/api/planets/") => {
//   return axios.get(url);
// };
// const fetchPlanets = (res) => {
//   const h1 = document.createElement("h1");
//   h1.innerText = "New Planets Data";
//   document.body.appendChild(h1);
//   const { results } = res.data;
//   const ul = document.createElement("ul");
//   results.forEach((result) => {
//     const li = document.createElement("li");
//     li.innerHTML = `Name:<b>${result.name}</b> <br> Rotation Period: ${result.rotation_period}`;
//     ul.appendChild(li);
//   });
//   document.body.appendChild(ul);
//   return Promise.resolve(res.data.next);
// };
// fetchURL()
//   .then(fetchPlanets)
//   .then(fetchURL)
//   .then(fetchPlanets)
//   .then(fetchURL)
//   .then(fetchPlanets)
//   .catch(() => {
//     console.log("Error Thrown");
//   });

//SEQUENTIAL AND PARALLEL REQUESTS
//1st sequential
// const pokiMon = async () => {
//   const poki1 = await axios.get("https://pokeapi.co/api/v2/pokemon/1");
//   const poki2 = await axios.get("https://pokeapi.co/api/v2/pokemon/2");
//   const poki3 = await axios.get("https://pokeapi.co/api/v2/pokemon/3");
//   console.log(poki1.data);
//   console.log(poki2.data);
//   console.log(poki3.data);
// };
// pokiMon();

//2nd parallel
const pokiMon = async () => {
  const prom1 = axios.get("https://pokeapi.co/api/v2/pokemon/1");
  const prom2 = axios.get("https://pokeapi.co/api/v2/pokemon/2");
  const prom3 = axios.get("https://pokeapi.co/api/v2/pokemon/3");
  // const poki1 = await prom1;
  // const poki2 = await prom2;
  // const poki3 = await prom3;
  // console.log(poki1);
  // console.log(poki2);
  // console.log(poki3);
  //BEST ALTERNATIVE IS Promise.all([promises])
  //it returns the promise until the all the promises passed init will be resolved
  const results = await Promise.all([prom1, prom2, prom3]);
  printData(results);
};
const printData = (results) => {
  results.forEach((element) => {
    console.log(element.data);
  });
};
pokiMon().catch(() => {
  console.log("Request fail 404");
});
