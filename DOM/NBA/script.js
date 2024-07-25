const warriorsGames = [
  {
    awayTeam: {
      team: "Golden State",
      points: 119,
      isWinner: true,
    },
    homeTeam: {
      team: "Houston",
      points: 109,
      isWinner: false,
    },
  },
  {
    awayTeam: {
      team: "Golden State",
      points: 105,
      isWinner: false,
    },
    homeTeam: {
      team: "Houston",
      points: 106,
      isWinner: true,
    },
  },
  {
    awayTeam: {
      team: "Houston",
      points: 129,
      isWinner: false,
    },
    homeTeam: {
      team: "Golden State",
      points: 130,
      isWinner: true,
    },
  },
  {
    homeTeam: {
      team: "Golden State",
      points: 120,
      isWinner: false,
    },
    awayTeam: {
      team: "Houston",
      points: 122,
      isWinner: true,
    },
  },
  {
    awayTeam: {
      team: "Golden State",
      points: 121,
      isWinner: true,
    },
    homeTeam: {
      team: "Houston",
      points: 122,
      isWinner: false,
    },
  },
  {
    homeTeam: {
      team: "Golden State",
      points: 124,
      isWinner: true,
    },
    awayTeam: {
      team: "Houston",
      points: 122,
      isWinner: false,
    },
  },
  {
    homeTeam: {
      team: "Houston",
      points: 125,
      isWinner: true,
    },
    awayTeam: {
      team: "Golden State",
      points: 122,
      isWinner: false,
    },
  },
  {
    awayTeam: {
      team: "Houston",
      points: 111,
      isWinner: false,
    },
    homeTeam: {
      team: "Golden State",
      points: 122,
      isWinner: true,
    },
  },
  {
    homeTeam: {
      team: "Golden State",
      points: 125,
      isWinner: false,
    },
    awayTeam: {
      team: "Houston",
      points: 128,
      isWinner: true,
    },
  },
  {
    awayTeam: {
      team: "Golden State",
      points: 105,
      isWinner: false,
    },
    homeTeam: {
      team: "Houston",
      points: 108,
      isWinner: true,
    },
  },
];

let container;
const makeChart = (games, targetTeam) => {
  container = document.createElement("div");
  const h1 = document.createElement("h1");
  console.log(targetTeam);
  if (targetTeam === "Golden State") {
    h1.innerText = `${targetTeam} Warriors`;
  } else {
    h1.innerText = `${targetTeam} Rockets`;
  }
  container.classList.add("container");
  document.body.appendChild(container);
  container.appendChild(h1);
  const ulParent = document.createElement("ul");
  for (let game of games) {
    const gameLi = document.createElement("li");
    gameLi.innerHTML = getScoreLine(game);
    gameLi.classList.add(isWinner(game, targetTeam) ? "win" : "loss");
    ulParent.appendChild(gameLi);
  }
  return ulParent;
};

const getScoreLine = (game) => {
  const { homeTeam, awayTeam } = game;
  const { team: hTeam, points: hPoints } = homeTeam;
  const { team: aTeam, points: aPoints } = awayTeam;
  const teamNames = `${aTeam} @ ${hTeam}`;
  let scoreLine;
  if (aPoints > hPoints) scoreLine = `<b>${aPoints}</b> @ ${hPoints}`;
  else scoreLine = `${aPoints} @ <b>${hPoints}</b>`;
  return `${teamNames} <===> ${scoreLine}`;
};

const isWinner = (game, targetTeam) => {
  const { homeTeam, awayTeam } = game;
  const target = homeTeam.team === targetTeam ? homeTeam : awayTeam;
  return target.isWinner;
};
const firstChart = makeChart(warriorsGames, "Golden State");
container.appendChild(firstChart);
const secChart = makeChart(warriorsGames, "Houston");
container.appendChild(secChart);
