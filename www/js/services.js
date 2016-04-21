angular.module('starter.services', [])

.factory('Chats', function() {
  // Might use a resource here that returns a JSON array

  // Some fake testing data
  var chats = [{
    id: 0,
    name: 'Cristo',
    lastText: 'Lugar turistico',
    face: 'img/cristo.jpg'
  }, {
    id: 1,
    name: 'Monumento',
    lastText: 'Monumento a las Cholitas',
    face: 'img/cholita.jpg'
  }, {
    id: 2,
    name: 'Avenida Heroinas',
    lastText: 'Avenida Heroinas',
    face: 'img/heroinas.jpg'
  }, {
    id: 3,
    name: 'Parque Acuatico',
    lastText: 'Parque Acuatico',
    face: 'img/parque-acuatico2.jpg'
  }];

  return {
    all: function() {
      return chats;
    },
    remove: function(chat) {
      chats.splice(chats.indexOf(chat), 1);
    },
    get: function(chatId) {
      for (var i = 0; i < chats.length; i++) {
        if (chats[i].id === parseInt(chatId)) {
          return chats[i];
        }
      }
      return null;
    }
  };
});
