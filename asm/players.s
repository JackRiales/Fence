;
; File generated by cc65 v 2.16 - Git e67bbcb
;
	.fopt		compiler,"cc65 v 2.16 - Git e67bbcb"
	.setcpu		"6502"
	.smart		on
	.autoimport	on
	.case		on
	.debuginfo	off
	.importzp	sp, sreg, regsave, regbank
	.importzp	tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
	.macpack	longbranch
	.import		_metaspr
	.export		_META_PLAYERONE
	.export		_player_init
	.export		_player_update
	.export		_player_draw

.segment	"RODATA"

_META_PLAYERONE:
	.byte	$06
	.byte	$00
	.byte	$50
	.byte	$00
	.byte	$06
	.byte	$08
	.byte	$60
	.byte	$00
	.byte	$0E
	.byte	$04
	.byte	$40
	.byte	$02
	.byte	$16
	.byte	$04
	.byte	$41
	.byte	$00
	.byte	$02
	.byte	$00
	.byte	$51
	.byte	$01
	.byte	$80

; ---------------------------------------------------------------
; void __near__ __fastcall__ player_init (__near__ struct player *, unsigned char)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_player_init: near

.segment	"CODE"

	jsr     pusha
	ldy     #$02
	lda     (sp),y
	sta     ptr1+1
	dey
	lda     (sp),y
	sta     ptr1
	dey
	lda     (sp),y
	sta     (ptr1),y
	ldy     #$02
	lda     (sp),y
	sta     ptr1+1
	dey
	lda     (sp),y
	sta     ptr1
	dey
	lda     (sp),y
	beq     L001C
	lda     #$AB
	jmp     L0037
L001C:	lda     #$55
L0037:	iny
	sta     (ptr1),y
	iny
	lda     (sp),y
	sta     ptr1+1
	dey
	lda     (sp),y
	sta     ptr1
	lda     #$32
	iny
	sta     (ptr1),y
	lda     (sp),y
	sta     ptr1+1
	dey
	lda     (sp),y
	sta     ptr1
	lda     #$00
	ldy     #$04
	sta     (ptr1),y
	iny
	sta     (ptr1),y
	ldy     #$02
	lda     (sp),y
	sta     ptr1+1
	dey
	lda     (sp),y
	sta     ptr1
	lda     #$08
	tay
	sta     (ptr1),y
	ldy     #$02
	lda     (sp),y
	sta     ptr1+1
	dey
	lda     (sp),y
	sta     ptr1
	lda     #$10
	ldy     #$09
	sta     (ptr1),y
	ldy     #$02
	lda     (sp),y
	sta     ptr1+1
	dey
	lda     (sp),y
	sta     ptr1
	lda     #$08
	ldy     #$0C
	sta     (ptr1),y
	ldy     #$02
	lda     (sp),y
	sta     ptr1+1
	dey
	lda     (sp),y
	sta     ptr1
	lda     #$10
	ldy     #$0D
	sta     (ptr1),y
	jmp     incsp3

.endproc

; ---------------------------------------------------------------
; void __near__ __fastcall__ player_update (__near__ struct player *)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_player_update: near

.segment	"CODE"

	jsr     pushax
	jmp     incsp2

.endproc

; ---------------------------------------------------------------
; void __near__ __fastcall__ player_draw (__near__ struct player *, __near__ unsigned char *)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_player_draw: near

.segment	"CODE"

	jsr     pushax
	ldy     #$03
	lda     (sp),y
	sta     ptr1+1
	dey
	lda     (sp),y
	sta     ptr1
	ldy     #$05
	lda     (ptr1),y
	tax
	dey
	lda     (ptr1),y
	jsr     bnegax
	bne     L002F
	jsr     decsp4
	ldy     #$07
	lda     (sp),y
	sta     ptr1+1
	dey
	lda     (sp),y
	sta     ptr1
	dey
	lda     (ptr1),y
	tax
	dey
	lda     (ptr1),y
	sta     ptr1
	stx     ptr1+1
	dey
	lda     (ptr1),y
	tax
	dey
	lda     (ptr1),y
	sta     (sp),y
	iny
	txa
	sta     (sp),y
	ldy     #$07
	lda     (sp),y
	sta     ptr1+1
	dey
	lda     (sp),y
	sta     ptr1
	ldy     #$01
	lda     (ptr1),y
	sta     (sp),y
	ldy     #$07
	lda     (sp),y
	sta     ptr1+1
	dey
	lda     (sp),y
	sta     ptr1
	ldy     #$02
	lda     (ptr1),y
	ldy     #$00
	sta     (sp),y
	ldy     #$05
	lda     (sp),y
	tax
	dey
	lda     (sp),y
	jsr     _metaspr
L002F:	jmp     incsp4

.endproc

