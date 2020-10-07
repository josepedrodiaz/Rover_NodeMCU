'use strict';

class App extends React.Component {
  render() {
    return (
      <div>
        <h1>HI</h1>
      </div>
    );
  }
}

const domContainer = document.querySelector('#app');
ReactDOM.render(App, domContainer);