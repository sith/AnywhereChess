#include <PieceHandle.h>

PieceHandle::PieceHandle(Piece *value) : value(value) {}

PieceHandle::~PieceHandle() {
    delete value;
}

bool PieceHandle::operator==(const PieceHandle &rhs) const {
    return value == rhs.value;
}

bool PieceHandle::operator!=(const PieceHandle &rhs) const {
    return !(rhs == *this);
}

PieceHandle::PieceHandle(PieceHandle &&pieceHandle) noexcept {
    value = pieceHandle.value;
    pieceHandle.value = nullptr;
}
