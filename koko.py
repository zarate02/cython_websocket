import asyncio
import websockets
import json
import uuid
import datetime
import asyncio

targetdate = {
    'type':'MainCH',
    'sessionId': str(uuid.uuid4()),     
    'publishedDate': datetime.datetime.now().strftime('%Y-%m-%dT%H:%M:%SZ'),
    'payload':{
        'pttid':'gg'
    }
}
jsondate = json.dumps(targetdate)

uri = "ws://localhost:1818"
async def getJson():
    async with websockets.connect(uri) as websocket:
        await websocket.send(jsondate)
        greeting = await websocket.recv()
        return greeting
        
def getResult():
    return asyncio.run(getJson())