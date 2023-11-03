import hashlib

def hashPassword(password):
    objeto_hash = hashlib.sha256()
    objeto_hash.update(password.encode('utf-8'))
    return objeto_hash.hexdigest()